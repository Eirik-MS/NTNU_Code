"""Filnavn


ploting/Frekvensforsterker_Scope.csv
ploting/Frekvensforsterker_Spectrum_RMS.csv

"""

import numpy as np 
import matplotlib.pyplot as plt 
import csv

header = []
data = []

filename = 'Network_Bondpass.csv'   #Henter data fra csvfil
with open(filename) as csvfile:
    csvreader = csv.reader(csvfile)  #Leser første linje i csv-fila (den med navn til kanalene)
    header = next(csvreader)
    for datapoint in csvreader:
        #print(datapoint)
        values = [float(value) for value in datapoint]
        data.append(values)

#Legger inn data fra hver kanal i hver sin liste
freq = [(p[0]) for p in data]
ch1 = [(p[1]) for p in data]
ch2 = [(p[2]) for p in data]

plt.plot(freq, ch1)
plt.plot(freq, ch2)
#Plot line on 2800Hz and show the value
plt.plot([2900, 2900], [0, -50], color='red')



plt.xlabel('Frekvens (Hz)')
plt.ylabel('Demping (dB)')
plt.xscale('log')
plt.grid(True)
plt.title('Amplitude respons')
plt.legend(['$V_s$', '$V_o$', '3000Hz'])

# lagre plot som png
plt.savefig('LaTex/Bilder/Network', dpi=600)

#plt.show()
