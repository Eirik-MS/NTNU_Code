#Plot the invers fourier transform of the signal

import numpy as np
import matplotlib.pyplot as plt


uendelig = 1000

def F(w, t):
    return (np.sin(w)/w)*np.exp(1j*w*t)

w = np.linspace(-uendelig, uendelig, 2000)
t = np.linspace(-np.pi, np.pi, 1000)


def plotF(w, t):
    y = []
    for i in range(len(t)):
        sum = 0
        for k in range(len(w)):
            sum += F(w[k], t[i])

        sum*1/np.pi
        y.append(sum)
    
    plt.plot(t, y, label='w=1')
    plt.show()

plotF(w, t)
    
    
