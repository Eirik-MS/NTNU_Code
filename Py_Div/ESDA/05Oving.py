#make bode plot of the circuit

import numpy as np
import matplotlib.pyplot as plt

#constants
R = 1000
L = 0.097
c = 1e-8

#frequency
f = np.logspace(0, 8, 1000)
amp = np.zeros(len(f))

#transfer function
def H_a(R, L, c, f):
    1/(np.sqrt(1-(-1/f*c*R+f*L/R)**2))

for i in range(len(f)):
    amp[i] = H_a(R, L, c, f[i])

print(amp)


#plot
plt.figure()
plt.loglog(f, amp)
plt.xlabel('Frequency [Hz]')
plt.ylabel('Amplitude')
plt.title('Bode plot of the circuit')
plt.show()
