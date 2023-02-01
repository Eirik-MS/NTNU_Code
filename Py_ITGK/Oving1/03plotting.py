from math import sin
import matplotlib.pyplot as plt
import numpy as np

xvalue = [-3,-1,1,3,5]
xvalue = np.linspace(xvalue[0], xvalue[-1], 200)
f_y = []
g_y = []
h_y = []

def f(x):
    return (x**2 - 3*x +2)

def g(x):
    return (3*sin(x))

def h(x):
    return (42 * x)/(x**2+4)

for x in xvalue:
    f_y.append(f(x))
    g_y.append(g(x))
    h_y.append(h(x))
    
axe = plt.figure().add_subplot(1, 1, 1)
axe.spines['left'].set_position('center')
axe.spines['bottom'].set_position('zero')
axe.spines['right'].set_color('none')
axe.spines['top'].set_color('none')
axe.xaxis.set_ticks_position('bottom')
axe.yaxis.set_ticks_position('left')



plt.plot(xvalue,f_y, label='f(x) = x^2 - 3x +2')
plt.plot(xvalue, g_y, label='g(x) = 3sin(x)')
plt.plot(xvalue, h_y, label='h(x) = (42x)/(x^2+4)')
plt.legend()
plt.show()
print(1)