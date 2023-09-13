#Plot data from an ocilloscope from csv file

import numpy as np
import matplotlib.pyplot as plt
import csv

# Open file
with open('Data/Scope_With_R_KL_1M_1V.csv', 'r') as csvfile:
    # Read file
    plots = csv.reader(csvfile, delimiter=',')
    # Create empty lists
    data = list(plots)
    data.pop(0)
    t = []
    ch1 = []
    ch2 = []
    # Fill lists with data
    for row in data:
        t.append(float(row[0]))
        ch1.append(float(row[1]))
        ch2.append(float(row[2])*1.15+2.17)

# Plot data
plt.plot(t,ch1, label='V')
plt.plot(t,ch2, label='V2')
plt.xlabel('Time (s)')
plt.ylabel('Voltage (V)')
plt.title('Oscilloscope Data')
plt.legend(loc= 'upper right' )
plt.show()
