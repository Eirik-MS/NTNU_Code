from cmath import pi, sin
import math
import numpy as np
import matplotlib.pyplot as plt

xverdier = np.linspace(-2, 5, 1000)
yverdier = []
#nteorden = int(input())

for x in xverdier:
    sum = 0
    yverdier.append(sin(x))

axe = plt.figure().add_subplot(1, 1, 1)
axe.spines['left'].set_position('center')
axe.spines['bottom'].set_position('zero')
axe.spines['right'].set_color('none')
axe.spines['top'].set_color('none')
axe.xaxis.set_ticks_position('bottom')
axe.yaxis.set_ticks_position('left')


plt.plot(xverdier, yverdier)
plt.show()