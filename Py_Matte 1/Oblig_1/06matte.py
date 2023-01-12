from math import sqrt
import matplotlib.pyplot as plt
import numpy as np

xvalue = [-3,-1,1,3]
xvalue = np.linspace(xvalue[0], xvalue[-1], 200)
f_y = []
g_y = []
h_y = []
j_y = []
i_y = []
k_y = []
l_y = []
m_y = [] 


def f(x):
    return (x-1)

def g(x):
    return (x+2)**2

def h(x):
    return (x**3-1)

def j(x):
    if x < 0.25: 
        return
    return (1+(4*x-1)**(1/2))

def i(x):
    return 1-x**(1/3)

def k(x):
    return (2-(1/x))

def l(x):
    if 1 < x or x > 1: return
    return (1-(1-x**2)**(1/2))

def m(x):
    return (1+abs(x+1))

for x in xvalue:
    f_y.append(f(x))
    g_y.append(g(x))
    h_y.append(h(x))
    j_y.append(j(x))
    i_y.append(i(x))
    k_y.append(k(x))
    l_y.append(l(x))
    m_y.append(m(x))

    
axe = plt.figure().add_subplot(1, 1, 1)
axe.spines['left'].set_position('center')
axe.spines['bottom'].set_position('zero')
axe.spines['right'].set_color('none')
axe.spines['top'].set_color('none')
axe.xaxis.set_ticks_position('bottom')
axe.yaxis.set_ticks_position('left')



plt.plot(xvalue, f_y, label='f(x) = x^2 - 3x +2')
plt.plot(xvalue, g_y, label='g(x) = 3sin(x)')
plt.plot(xvalue, h_y, label='h(x) = (42x)/(x^2+4)')
plt.plot(xvalue, j_y, label='j(x) = 1+ sqrt(4*x-1)')
plt.plot(xvalue, i_y, label='i(x) = 1-x**(1/3)')
plt.plot(xvalue, k_y, label='k(x) = (2-(1/x))')
plt.plot(xvalue, l_y, label='l(x) = (1-sqrt(1-x**2))')
plt.plot(xvalue, m_y, label='m(x) = (1+abs(x+1))')
plt.ylim(-5, 10)
plt.legend()
plt.show()
print(1)

