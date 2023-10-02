#find all files in current directory that start with 'Spectrum' and is a .csv file

import os
import glob

def find_scope_files():
    scope_files = []
    for file in glob.glob("Spectrum*.csv"):
        scope_files.append(file)
    return scope_files


# Sample multidimensional list
data1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
data2 = [['a', 'b', 'c'], ['d', 'e', 'f'], ['g', 'h', 'i']]

# Creating a dictionary to associate filenames with data
file_data = {
    'file1.txt': data1,
    'file2.txt': data2
}

# Accessing data using filenames
print("Data for file1.txt:")
print(file_data['file1.txt'])

print("\nData for file2.txt:")
print(file_data['file2.txt'])