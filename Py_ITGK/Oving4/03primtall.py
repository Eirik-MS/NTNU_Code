import math

def divisable(a, b):
    if a % b == 0:
        return True
    else:
        return False

def is_prime(a):
    for i in range(2, a-1):
        if divisable(a, i):
            return False
    return True

def is_prime2(a):
    if divisable(a, 2): return False
    for i in range(3,round(math.sqrt(a)+0.5), 2):
        if divisable(a, i):
            return False
    return True

print(is_prime2(13))
