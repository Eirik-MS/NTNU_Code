import numpy as np
import matplotlib.pyplot as plt


def andregradslikning(a,b ,c):
    if a == 0:
        return "a kan ikke være 0"
    d = b**2 - 4*a*c
    if d < 0:
        return f'Andregradsligningen {a}x^2 + {b}x + {c} har to imaginære løsninger'
    elif d == 0:
        løs = (-b)/(2*a)
        print(f'Andregradsligningen {a}x^2 + {b}x + {c} har en reell løsning {løs}')
        return løs
    else:
        løs = (-b + np.sqrt(d))/(2*a), (-b - np.sqrt(d))/(2*a)
        print(f'Andregradsligningen {a}x^2 + {b}x + {c} har to reelle løsningene {løs[0]} og {løs[1]}')
        return løs

print(andregradslikning(1,2,6))