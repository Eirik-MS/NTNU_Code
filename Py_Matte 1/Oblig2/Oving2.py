import numpy as np
import matplotlib.pyplot as plt

def euler_implisitt(T, n):
    h = T/n
    t = np.arange(0.0, (n+1)*h, h)
    y = np.zeros(n+1)
    #bruker dobbel for-løkke for å gjøre fikspunktitterasjon på hver enklet ligningsløsnig
    
    for k in range(n):
        for j in range(100):
            y[k+1] = y[k] + h*(1-y[k+1]**2)
            
    plt.plot(t, y)
    plt.show()

    return y

print(euler_implisitt(4, 100))