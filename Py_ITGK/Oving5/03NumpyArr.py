import numpy as np

def areOrthogonal(a,b):
    arr1 = np.array(a)
    arr2 = np.array(b)

    if np.dot(arr1,arr2) == 0:
        return True
    else: return False

arr = np.arange(1,16).reshape(3,5)
arr = np.transpose(arr)
print(arr)
