#find all files in current directory that start with 'spectrum' and is a .csv file

import os
import glob
import numpy as np
import matplotlib.pyplot as plt
import argparse

parser = argparse.ArgumentParser(description='A script with command-line arguments.')
parser.add_argument('-d', '--dir', type=str, help='The directory to save the plot to. Defaults to current directory.', default='')
parser.add_argument('-f', '--file', type=str, help='The file to plot. Defaults to all files in the current directory.', default='')
parser.add_argument('-ph', '--Phase', action='store_true', help='Plot phase as well')
parser.add_argument('-ch_1', '--channel_1', type=str, help='Name of Channel 1, defaluts to Channel 1', default='Channel 1')
parser.add_argument('-ch_2', '--channel_2', type=str, help='Name of Channel 2, defaluts to Channel 2', default='Channel 2')
parser.add_argument('-thd', '--THD', action='store_true', help='Plot THD as well')


def find_spectrum_files():
    spectrum_files = []
    for file in glob.glob("spectrum*.csv"):
        spectrum_files.append(file)
    return spectrum_files

#get the data from the spectrum files and generate a plot for each file
def get_spectrum_data(spectrum_files):
    data_dict = {}
    for file in spectrum_files:
        data = np.loadtxt(file, delimiter=',', skiprows=1)
        #round firs collum to 0 decimals
        data[:,0] = np.round(data[:,0], 0)  
        data_dict[file] = data
    return data_dict

#save the data from the spectrum as a bodeplot
def save_spectrum_plot(data_dict, args):
    saveDir = args.dir

    
    for key in data_dict:
        mag1 = np.abs(data_dict[key][:,1])
        mag2 = np.abs(data_dict[key][:,3])
        if np.max(mag1) > np.max(mag2):
            strongest = data_dict[key][:,1]
            weakest = data_dict[key][:,3]
        else:
            strongest = data_dict[key][:,3]
            weakest = data_dict[key][:,1]


        if args.Phase:
            #generate two subplots one for voltage and one for phase
            fig, (ax1, ax2) = plt.subplots(2, 1, sharex=True)
            #plot the voltage
            ax1.plot(data_dict[key][:,0], strongest)
            ax1.plot(data_dict[key][:,0], weakest)
            ax1.set_ylabel('Voltage (V)')
            ax1.set_title(key)
            #plot the phase
            ax2.plot(data_dict[key][:,0], data_dict[key][:,2])
            ax2.plot(data_dict[key][:,0], data_dict[key][:,5])
            ax2.set_ylabel('Phase (deg)')
            ax2.set_xlabel('Frequency (Hz)')
            #save the plot
        else:
            plt.plot(data_dict[key][:,0], strongest)
            plt.plot(data_dict[key][:,0], weakest)
            plt.xlabel('Frequency (Hz)')
            plt.ylabel('Voltage (V)')
            plt.title(key)
            plt.legend([args.channel_1, args.channel_2])
            #plt.show()
        
        


        print('Saving plot to:')
        print(os.path.join(saveDir, key[:-4] + '.png'))
        savePath = os.getcwd() + os.path.join(saveDir, key[:-4] + '.png')
        #print(savePath)
        plt.savefig(savePath, dpi = 600)
        plt.clf()

def calculate_THD(data_dict, freq):
    #calculate Total Harmonic Distortion
    for key in data_dict:
        #find a given frequency 
        #find to div4 and mult4 because of limited bandwidth
        #frequency = 1000
        index_1000 = np.where(data_dict[key][:,0] == freq)
        freq_val1 = data_dict[key][index_1000[0],1]
        freq_val2 = data_dict[key][index_1000[0],3]
        
        index_div2 = np.where(data_dict[key][:,0] == freq/2)
        freq_val1_div2 = data_dict[key][index_div2[0],1]
        freq_val2_div2 = data_dict[key][index_div2[0],3]
        
        index_div4 = np.where(data_dict[key][:,0] == freq/4)
        freq_val1_div4 = data_dict[key][index_div4[0],1]
        freq_val2_div4 = data_dict[key][index_div4[0],3]
        
        index_mult2 = np.where(data_dict[key][:,0] == freq*2)
        freq_val1_mult2 = data_dict[key][index_mult2[0],1]
        freq_val2_mult2 = data_dict[key][index_mult2[0],3]
        
        index_mult3 = np.where(data_dict[key][:,0] == freq*3)
        freq_val1_mult3 = data_dict[key][index_mult3[0],1]
        freq_val2_mult3 = data_dict[key][index_mult3[0],3]
        
        index_mult4 = np.where(data_dict[key][:,0] == freq*4)
        freq_val1_mult4 = data_dict[key][index_mult4[0],1]
        freq_val2_mult4 = data_dict[key][index_mult4[0],3]
        
        
        zero = data_dict[key][0,3]
        #sum of Val 2
        sum_val2 = np.sum(freq_val2_div2)**2 + np.sum(freq_val2_div4)**2 + np.sum(freq_val2_mult2)**2+ np.sum(freq_val2_mult3)**2 + np.sum(freq_val2_mult4)**2
        
        thd = np.sqrt(sum_val2)/freq_val2
        thd2 = np.sqrt(sum_val2+zero)/freq_val2
        print(f'THD for {key} is {round(thd[0]*100, 2)}% or {round(thd2[0]*100, 2)}%')
        

        #print(f'Index of {freq} is {index_1000} and has value {freq_val1} and {freq_val2}')


#main function
def main():
    args = parser.parse_args()
    
    #Command-line arguments
    if args.file:
        spectrum_files = [args.file]

    #Get the spectrum files
    if not args.file:
        spectrum_files = find_spectrum_files()

    ##Collect data from the spectrum files
    data_dict = get_spectrum_data(spectrum_files)

    if args.THD:
        calculate_THD(data_dict, 1000)
        return
    
    save_spectrum_plot(data_dict, args)
    

if __name__ == '__main__':
    main()
