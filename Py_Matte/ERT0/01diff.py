import numpy as np
import matplotlib.pyplot as plt

T=20
N=200
h=T/N

x = np.zeros(N+1)
y = np.zeros(N+1)
t = np.zeros(N+1)

x[0] =2
y[0] =2

for i in range(N):
    x [ i +1] = x [ i ]+h * x [ i ] * (1 - y [ i ])
    y [ i +1] = y [ i ]+h * y [ i ] * (x [ i ] -1)
    t [ i +1] = t [ i ]+h
    print(x[i], y[i], t[i])

axe = plt.figure().add_subplot(1, 1, 1)
axe.spines['bottom'].set_position('zero')
axe.spines['right'].set_color('none')
axe.spines['top'].set_color('none')
axe.xaxis.set_ticks_position('bottom')
axe.yaxis.set_ticks_position('left')
    

plt.plot(t,x, label='x(t)')
plt.plot(t,y, label='y(t)')
plt.plot(x,y, label='x(t) vs y(t)')
plt.show()

#%%% Oppgave 2 Fra nettet
# Importing libraries

import numpy as np
import matplotlib.pyplot as plt

T = 10
N = 5000
h = T/N


x = np.zeros(N+1)
y = np.zeros(N+1)
t = np.zeros(N+1)

x[0] = 1
y[0] = 1

def f(x, y):
    return y

def g(x, y):
    return -x+(-2*x**2+2)

for i in range(N): 
    x[i+1] = x[i] + h * f(x[i], y[i])
    y[i+1] = y[i] + h * g(x[i], y[i])
    t[i+1] = t[i] + h
        

axe = plt.figure().add_subplot(1, 1, 1)
axe.spines['bottom'].set_position('zero')
axe.spines['right'].set_color('none')
axe.spines['top'].set_color('none')
axe.xaxis.set_ticks_position('bottom')
axe.yaxis.set_ticks_position('left')

#plt.plot(t,x, label='x(t)')
plt.plot(t,y, label='y(t)')
plt.show()
# %%
