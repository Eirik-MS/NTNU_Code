import numpy as np
import matplotlib.pyplot as plt


def f(x, y):
    return y

def g(x, y):
    return -y/(1+x)-2*(x+y)

def frequency_dubbler(N = 1000, T = 10):
    x = np.zeros(N+1)
    y = np.zeros(N+1)
    t = np.zeros(N+1)

    x[0] = 1
    y[0] = 1
    h = T/N
    
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

    plt.plot(t,x, label='x(t)')
    plt.plot(t,y, label='y(t)')
    plt.plot(x,y, label='x(t) vs y(t)')
    plt.show()
    return x, y, t

frequency_dubbler()