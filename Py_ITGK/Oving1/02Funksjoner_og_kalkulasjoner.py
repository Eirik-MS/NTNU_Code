from cmath import sqrt
from math import cos, sin, sqrt
from re import A


a = 2
b = 3
c =5*a+b
d = a*b+c
e = (-b + 4)/(a-4)
f = 5**(a*b+2)
g = (𝑎+𝑏)* 𝑐 - 𝑑

# fjern komentarene på koden under hvis man vil teste koden over.

print(a)
print(b)
print(c)
print(d)
print(e)
print(f)
print(g)

#test å skrive noen små matematiske funksjoner
def f(x):
    return 2*x+1

def g(x):
    return (-4 * x +2)/(5*x+3)

def h(x):
    return (x**2 +2*x+1)

def i(x):
    return sqrt(x)

def j(x):
    return sin(x) + cos(x)


print(f(10))
print(g(5))
print(h(3))
print(i(4))
print(j(5))

#test modulus


def antall_minutt_sekund(sek):
    min = sek // 60
    return min

def antall_dogn_timer(timer):
    dogn = timer // 24
    return dogn

def antall_timer_minutt_sekund(sek):
    min = antall_minutt_sekund(sek)
    timer = min // 60   
    min = min % 60
    return [timer, min]



print(antall_minutt_sekund(120))
print(antall_dogn_timer(75))
print(antall_timer_minutt_sekund(19832))
