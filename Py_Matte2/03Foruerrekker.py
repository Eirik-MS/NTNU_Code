import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(-np.pi-1, np.pi+1, 1000)
y = []
y2 = []
y3 = []

def S(N, t):
    summ = 0
    for n in range(1, N):
        summ += 1/(2*n-1)*np.sin(2*n-1)*t
    summ = summ*(2/np.pi)
    summ += 1/2
    return summ

for i in range(0, len(t)):
    y.append(S(1000, t[i]))
    y2.append(S(5, t[i]))
    y3.append(S(7, t[i]))

plt.plot(t, y, label='n=1')
plt.plot(t, y2, label='n=2')
plt.plot(t, y3, label='n=3')

plt.show()


