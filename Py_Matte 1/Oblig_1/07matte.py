from math import sin
import matplotlib.pyplot as plt
import numpy as np

#x = y * sin y


Yverdi = np.linspace(-20, 20, 200)
Xverdi = []

def f(y):
    return y*sin(y)

for y in Yverdi:
    Xverdi.append(f(y))


axe = plt.figure().add_subplot(1, 1, 1)
axe.spines['left'].set_position('center')
axe.spines['bottom'].set_position('zero')
axe.spines['right'].set_color('none')
axe.spines['top'].set_color('none')
axe.xaxis.set_ticks_position('bottom')
axe.yaxis.set_ticks_position('left')


plt.plot(Xverdi, Yverdi, label = "Y * Sin(Y)")
plt.legend()
plt.show()