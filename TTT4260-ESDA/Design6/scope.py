#find all files in current directory that start with 'scope' and is a .csv file

import os
import glob
import numpy as np
import matplotlib.pyplot as plt

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

#plot the data from the scope files using matplotlib with two scope channels
def plot_scope_data(data_dict, saveDir=''):
    for key in data_dict:
        plt.plot(data_dict[key][:,0], data_dict[key][:,1], label='Channel 1')
        plt.plot(data_dict[key][:,0], data_dict[key][:,2], label='Channel 2')
        plt.xlabel('Time (s)')
        plt.ylabel('Voltage (V)')
        plt.title(key)
        plt.legend()
        plt.savefig(f'{saveDir}/{key}.png')

#main function
def main():
    #if -h or --help is specified, print the help message
    if '-h' in sys.argv or '--help' in sys.argv:
        print('Usage: python3 scope.py')
        print('Plots the data from the scope files in the current directory')
        print('The scope files must start with \'scope\' and be a .csv file')
        print('The plot will be saved in the current directory')
        print('The plot will be saved with the same name as the scope file')
        print('Example: python3 scope.py')
        print('Example: python3 scope.py -d /home/pi/Desktop')
        print('Example: python3 scope.py --dir /home/pi/Desktop')
        print('Example: python3 scope.py -h')
        print('Example: python3 scope.py --help')
        print('Author: Matthew Yu, Array Lead (2020-2021)')
        print('Advisor: Dr. Nicholas Gans')
        print('Arizona State University')
        print('Updated: 20 July 2021')
        return
    
    scope_files = find_scope_files()
    data_dict = get_scope_data(scope_files)
    plot_scope_data(data_dict)
    

if __name__ == '__main__':
    main()
