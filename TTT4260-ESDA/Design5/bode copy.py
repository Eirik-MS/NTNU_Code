import matplotlib.pyplot as plt
import csv

# plot bode plot for a rcl circuit from csv file

#bodeReadFile = 'bode1K.csv'
#bodeWriteFile = './LaTeX/Bilder/bode1K.png'

bodeReadFile = 'Data/V1_No_RL_Network.csv'
bodeWriteFile = './LaTeX/Bilder/bode2x1K.png'

Frequency = []
C1_gain = []
C2_gain = []
phase = []

with open('Data/V1_No_RL_Network.csv', 'r') as f:
    reader = csv.reader(f)
    data = list(reader)
    
#discard the first row
for i in range(1,35):
        data.pop(0)


for row in data:
    Frequency.append(float(row[0]))
    C1_gain.append(float(row[1]))
    C2_gain.append(float(row[2]))
    phase.append(float(row[3]))

#Plot db Gain and phase shift of signal

#find index and value of max gain
#max_gain = min(C2_gain)
#max_gain_index = C2_gain.index(max_gain)
#max_gain_freq = round(Frequency[max_gain_index], 0)

#find gain value of 2489Hz
#for i in range(len(Frequency)):
#	if Frequency[i] >= 2489:
#		gain_2489 = C2_gain[i]
#		index = i
#		actual = (C2_gain[i] + C2_gain[i-1])/2
#		print('Gain at 2489 Hz: ' + str(actual) + ' dB')
#		break



#plot
plt.figure(1)
plt.subplot(211)
plt.semilogx(Frequency, C1_gain, label='V')
plt.semilogx(Frequency, C2_gain, label='V2')
#plt.axvline(24, color='g', label='24 Hz' + ', ' + str(round(C2_gain[30],1)) + ' dB')
#plt.axvline(2697809, color='g', label='2.7 MHz' + ', ' + str(round(C2_gain[143],1)) + ' dB')

plt.legend()
plt.ylabel('Gain (dB)')
plt.subplot(212)
plt.semilogx(Frequency, phase)
plt.xlabel('Frequency (Hz)')
plt.ylabel('Phase (deg)')
#plt.savefig(bodeWriteFile, dpi=600)
plt.show()

# Save plot


