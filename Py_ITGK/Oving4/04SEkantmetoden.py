
import numpy as np


def f(x):
    return (x-12)*np.e**(x/2)-8*(x+2)**2

def g(x):
    return -x-2*x**2-5*x**3+6*x**4

print(f(0))
print(g(1))

def differeniate(x_k, x_k1, func):
    return (func(x_k1) - func(x_k))/(x_k1 - x_k)

print(differeniate(9,10,f))

def secant(x0, x1, func, tol):
    x_k1 = 0
    while abs(x0-x1) > tol:
        x_k1 = x1 - func(x1)/(differeniate(x1,x0,func))
        x0 = x1
        x1 = x_k1
    return x1 , func(x_k1)

print(secant(11,13,f,0.00001))
print(secant(1,2,g,0.00001))
print(secant(0,1,g,0.00001))