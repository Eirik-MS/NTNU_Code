import matplotlib.pyplot as plt


## Plot the spectrum analysis of another signal from csv file
#spectrumReadFile = 'spectrum2K.csv'
#spectrumWriteFile = './LaTeX/Bilder/spectrum2K.png'

spectrumReadFile = 'spectrum2x1K.csv'
spectrumWriteFile = './LaTeX/Bilder/spectrum2x1K.png'

Frequency = []
C1_gain = []
C2_gain = []
C1_phase = []
C2_phase = []

# read csv file
with open(spectrumReadFile, 'r') as f:
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
		C2_gain.append(float(split_line[3]))
		C1_phase.append(float(split_line[2]))
		C2_phase.append(float(split_line[4]))

#find index and value of max gain
max_gain = max(C2_gain)
max_gain_index = C2_gain.index(max_gain)
max_gain_freq = round(Frequency[max_gain_index], 0)

#find gain value after reduction
red_gain = C1_gain[max_gain_index]

#Plot the spectrum analysis without phase

plt.semilogx(Frequency, C2_gain, label='C1')
plt.semilogx(Frequency, C1_gain, label='C2')
plt.semilogx(max_gain_freq, max_gain, 'ro', label=str(max_gain_freq) + ' Hz' + ', ' + str(round(max_gain,1)) + ' dB')
plt.semilogx(max_gain_freq, red_gain, 'go', label='2489 Hz' + ', ' + str(round(red_gain,1)) + ' dB')
plt.legend()
plt.xlabel('Frequency (Hz)')
plt.ylabel('Gain (dB)')
#plt.savefig(spectrumWriteFile, dpi=600)
plt.show()
