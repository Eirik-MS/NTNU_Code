import numpy as np

def circumference_oval(a, b):
    """Calculate the circumference of an oval with a and b as major and minor axis.
    """
    return 2*np.pi * np.sqrt((a**2 + b**2)/2)

print(circumference_oval(2, 1))

