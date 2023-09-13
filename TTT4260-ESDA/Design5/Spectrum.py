#Plot a spectrum analisys of a signal in the given csv file

import numpy as np
import matplotlib.pyplot as plt
import csv

with open('Data/V1_No_RL_Network.csv', 'r') as f:
    reader = csv.reader(f)
    data = list(reader)
    
#discard the first row
for i in range(1,35):
        data.pop(0)

freq = []
trace1 = []
phase1 = []
trace2 = []
phase2 = []

for row in data:
    freq.append(float(row[0]))
    trace1.append(float(row[1]))
    trace2.append(float(row[2]))
    phase2.append(float(row[3]))

#Plot db Gain and phase shift of signal



plt.semilogx(freq, trace1, 'b')
plt.semilogx(freq, trace2, 'r')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Amplitude (dBm)')
plt.title('Spectrum')
plt.grid(True)


plt.savefig('./LaTeX/Bilder/Spectrum.png')
