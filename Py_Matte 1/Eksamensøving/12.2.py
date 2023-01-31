#solve circomfrance of eclipse using trapets rule
import numpy as np

a = 2
b = 1

N = 1000000
Dx = a/N

def df(x):
    return -b*(x**2) * (1/np.sqrt(1-(x**2/a**2))) * x

def phi(x):
    return np.sqrt(1+(df(x)**2))

def trapets_rule():
    sum = 0
    for i in range(1,N-1):
        x_i = i*Dx
        sum += (phi(x_i) + phi(x_i+Dx))*Dx/2
        if i % 1000 == 0 : print(i)
    return sum

print(trapets_rule())