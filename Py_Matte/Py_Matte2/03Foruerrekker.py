import numpy as np
import matplotlib.pyplot as plt
n = 10
t = np.linspace(-np.pi, np.pi, 1000)
y = []
y2 = []
y3 = []

def S(N, t):
    summ = 0
    for n in range(1, N):
        summ += 1/(2*n-1)*np.sin((2*n-1)*t)
    summ = summ*(2/np.pi)
    summ += 1/2
    return summ

for i in t:
    y.append(S(n, i))
    

plt.plot(t, y, label='n=1')


plt.show()


