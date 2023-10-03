#find all files in current directory that start with 'scope' and is a .csv file

import os
import glob
import numpy as np
import matplotlib.pyplot as plt
import argparse

parser = argparse.ArgumentParser(description='A script with command-line arguments.')
parser.add_argument('-d', '--dir', type=str, help='The directory to save the plot to. Defaults to current directory.', default='')
parser.add_argument('-f', '--file', type=str, help='The file to plot. Defaults to all files in the current directory.', default='')
parser.add_argument('-ch_1', '--channel_1', type=str, help='Name of Channel 1, defaluts to Channel 1', default='Channel 1')
parser.add_argument('-ch_2', '--channel_2', type=str, help='Name of Channel 2, defaluts to Channel 2', default='Channel 2')
parser.add_argument('-amp', '--Amplitude', action='store_true', help='Plot amplitude as well')

def find_scope_files():
    scope_files = []
    for file in glob.glob("scope*.csv"):
        scope_files.append(file)
    return scope_files

#get the data from the scope files and generate a plot for each file
def get_scope_data(scope_files):
    data_dict = {}
    for file in scope_files:
        data = np.loadtxt(file, delimiter=',', skiprows=1)
        data_dict[file] = data
    return data_dict

#save the data from the scope files using matplotlib with two scope channels
def save_scope_plot(data_dict, channel_1, channel_2, saveDir):
    for key in data_dict:
        plt.plot(data_dict[key][:,0], data_dict[key][:,1])
        plt.plot(data_dict[key][:,0], data_dict[key][:,2])
        plt.xlabel('Time (s)')
        plt.ylabel('Voltage (V)')
        plt.title(key)
        plt.legend([channel_1, channel_2])
        print('Saving plot to:')
        print(os.path.join(saveDir, key[:-4] + '.png'))
        savePath = os.getcwd() + os.path.join(saveDir, key[:-4] + '.png')
        #print(savePath)
        plt.savefig(savePath, dpi = 600)
        plt.clf()

def calculate_amplitude(data_dict, args):
    for key in data_dict:
        print(key)
        print('Amplitude of Channel 1: ' + str(round(np.max(data_dict[key][:,1]) - np.min(data_dict[key][:,1]), 5)) + 'V')
        print('Amplitude of Channel 2: ' + str(round(np.max(data_dict[key][:,2]) - np.min(data_dict[key][:,2]), 5)) + 'V')
        #calculate the amplification of the circuit
        print('Amplification: ' + str(round((np.max(data_dict[key][:,2]) - np.min(data_dict[key][:,2])) / (np.max(data_dict[key][:,1]) - np.min(data_dict[key][:,1])), 5)))
        print('Amplification in db: ' + str(round(20*np.log10((np.max(data_dict[key][:,1]) - np.min(data_dict[key][:,1]))/(np.max(data_dict[key][:,2]) - np.min(data_dict[key][:,2]))), 5)) + 'dB')

#main function
def main():
    args = parser.parse_args()

    #Global variables
    saveDir = os.getcwd()
    channel_1 = args.channel_1
    channel_2 = args.channel_2
    
    
    #Command-line arguments
    if args.dir:
        saveDir = args.dir
    if args.file:
        scope_files = [args.file]

    #Get the scope files
    if not args.file:
        scope_files = find_scope_files()
    data_dict = get_scope_data(scope_files)

    if args.Amplitude:
        calculate_amplitude(data_dict, args)
        return



    #Get the data from the scope files and generate a plot for each file
    save_scope_plot(data_dict, channel_1, channel_2, saveDir)
    

if __name__ == '__main__':
    main()
