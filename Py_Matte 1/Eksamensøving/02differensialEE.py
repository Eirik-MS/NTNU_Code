#solve second order ordinary differential equation with euler method

import numpy as np
import matplotlib.pyplot as plt

#constants:
b = 1
c = 1
N=1000

time = np.linspace(0,10,N)
Z1 = np.zeros(N)
Z2 = np.zeros(N)

Z1[0] = 0
Z2[0] = 1

def Z1_dx(Z1,Z2):
    return Z2

def Z2_dx(Z1,Z2):
    return -b*Z2 - c*Z1

def euler(Z1,Z2):
    for i in range(100):
        Z1[i+1] = Z1[i] + Z1_dx(Z1[i],Z2[i])*0.01
        Z2[i+1] = Z2[i] + Z2_dx(Z1[i],Z2[i])*0.01
    return Z1,Z2

Z1,Z2 = euler(Z1,Z2)

plt.plot(time,Z1)
plt.plot(time,Z2)
plt.show()
