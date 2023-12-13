import matplotlib.pyplot as plt

# plot bode plot for a rcl circuit from csv file

#bodeReadFile = 'bode1K.csv'
#bodeWriteFile = './LaTeX/Bilder/bode1K.png'

bodeReadFile = './Design7/Network_Butterworth.csv'
bodeWriteFile = './Design7/LaTeX/Bilder/bode.png'

Frequency = []
C1_gain = []
C2_gain = []
phase = []

# read csv file
with open(bodeReadFile, 'r') as f:
	data = f.readlines()
	# remove header
	header = data[0]
	data = data[1:]
	for line in data:
		# split line
		split_line = line.split(',')
		# append to lists
		Frequency.append(float(split_line[0]))
		C1_gain.append(float(split_line[1]))
		C2_gain.append(float(split_line[2]))
		phase.append(float(split_line[3]))

#find index and value of max gain
max_gain = min(C2_gain)
max_gain_index = C2_gain.index(max_gain)
max_gain_freq = round(Frequency[max_gain_index], 0)

#find gain value of 2489Hz
for i in range(len(Frequency)):
	if Frequency[i] >= 2489:
		gain_2489 = C2_gain[i]
		index = i
		actual = (C2_gain[i] + C2_gain[i-1])/2
		print('Gain at 2489 Hz: ' + str(actual) + ' dB')
		break


#plot
#plt.figure(1)
#plt.subplot(211)
plt.semilogx(Frequency, C1_gain, label='$V_1$')
plt.semilogx(Frequency, C2_gain, label='$V_2$')
# add linese on 1.2kHz and 1.7kHz
plt.axvline(x=1275, color='r', linestyle='--', label='1.2 kHz, -1.6dB')
plt.axvline(x=1700, color='g', linestyle='--', label='1.7 kHz, -12dB')

plt.legend()
plt.ylabel('Gain (dB)')
#plt.subplot(212)
#plt.semilogx(Frequency, phase)
#plt.xlabel('Frequency (Hz)')
#plt.ylabel('Phase (deg)')
plt.savefig(bodeWriteFile, dpi=600)
#plt.show()

# Save plot


