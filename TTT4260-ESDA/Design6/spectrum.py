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

def calculate_THD(data_dict):
    #calculate Total Harmonic Distortion
    for key in data_dict:
        mag1 = np.abs(data_dict[key][:,1])
        mag2 = np.abs(data_dict[key][:,3])
        if np.max(mag1) > np.max(mag2):
            strongest = data_dict[key][:,1]
            weakest = data_dict[key][:,3]
        else:
            strongest = data_dict[key][:,3]
            weakest = data_dict[key][:,1]
        THD = np.sqrt(np.sum(weakest**2)/np.sum(strongest**2))
        print('THD for ' + key + ' is ' + str(round(THD*100, 3)) + '%')


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
        calculate_THD(data_dict)
        return
    
    save_spectrum_plot(data_dict, args)
    

if __name__ == '__main__':
    main()
