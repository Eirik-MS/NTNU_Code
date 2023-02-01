import numpy as np
import math

def f(x):
    if x == 0:
        return
    return x**2*np.sin(1/x)

def hastighet(tid):
    if tid >= 10:
        return round(10*9.81, 2)
    return round(tid*9.81,2)

print(hastighet(5))
print("Riktig svar: 49 m/s")

print(hastighet(0))
print("Riktig svar: 0 m/s")

print(hastighet(15))
print("Riktig svar: 98 m/s")

print(hastighet(10))
print("Riktig svar: 98 m/s")