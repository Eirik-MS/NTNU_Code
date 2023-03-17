import matplotlib.pyplot as plt

# plot bode plot for a rcl circuit from csv file

#bodeReadFile = 'bode1K.csv'
#bodeWriteFile = './LaTeX/Bilder/bode1K.png'

bodeReadFile = 'bode2x1K.csv'
bodeWriteFile = './LaTeX/Bilder/bode2x1K.png'

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
		C1_gain.append(float(split_line[3]))
		C2_gain.append(float(split_line[1]))
		phase.append(float(split_line[2]))

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
plt.figure(1)
plt.subplot(211)
plt.semilogx(Frequency, C1_gain, label='C1')
plt.semilogx(Frequency, C2_gain, label='C2')
plt.axvline(2489, color='g', label='2489 Hz' + ', ' + str(round(actual,1)) + ' dB')
plt.axvline(max_gain_freq, color='r', linestyle='dotted', label=str(max_gain_freq) + ' Hz' + ', ' + str(round(max_gain,1)) + ' dB')
plt.legend()
plt.ylabel('Gain (dB)')
plt.subplot(212)
plt.semilogx(Frequency, phase)
plt.xlabel('Frequency (Hz)')
plt.ylabel('Phase (deg)')
plt.savefig(bodeWriteFile, dpi=600)
#plt.show()

# Save plot


