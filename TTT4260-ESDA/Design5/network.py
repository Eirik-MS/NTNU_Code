#Plot an network analyzer data from csv file

import numpy as np
import matplotlib.pyplot as plt
import csv

# Open file
with open('network_1.csv', 'r') as csvfile:
    # Read file
    plots = csv.reader(csvfile, delimiter=',')
    # Discard first row
    
    # Create empty lists
    f = []
    s11 = []
    s12 = []
    s21 = []
    s22 = []
    # Fill lists with data
    for row in plots:
        f.append(float(row[0]))
        s11.append(float(row[1]))
        s12.append(float(row[2]))
        s21.append(float(row[3]))
        s22.append(float(row[4]))

# Plot data
plt.plot(f,s11, label='S11')
plt.plot(f,s12, label='S12')
plt.plot(f,s21, label='S21')
plt.plot(f,s22, label='S22')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude (dB)')
plt.title('Network Analyzer Data')
plt.legend()
plt.show()
