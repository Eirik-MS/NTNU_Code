import numpy as np


#%% Oppgave 7 - Newtons metode og fikspunktitterasjon for likninger med flere ukjente
import numpy as np

def fikspunkt7(x):
    count = 0
    # tester funksjonen med cos x
    for i in range(1, 1000):
        #print(x)
        xold = x        
        x = (2*np.sin(2*x)+np.pi)/4
        if xold == x: break
        count+=1

    return [x, count]

def newtons7(x):
    count = 0
    for i in range(1, 1000):
        xold = x
        x = x - (2*np.sin(2*x)+np.pi-4*x)/(4*np.cos(2*x)-4)
        if xold == x: break
        count+=1

    return [x, count]

svar1 = np.cos(fikspunkt7(1)[0])
svar2 = np.cos(newtons7(1)[0])

print(f' Opg7 Fikspunk: {svar1} ')
print(f' Opg7 Newtons: {svar2} ')

#%%
# Oppgave 8 - Newtons metode for x^2 -2
import numpy as np


def newtons8(x):
    count = 0
    for i in range(1, 1000):
        xold = x
        x = x - (x**2-2)/(2*x)
        if xold == x: break
        count+=1

    return [x, count]

print(f' Opg8 Newtons: {newtons8(1)} ')

#Ja det konvergerer mot et reelt tall 

# %%

import numpy as np


def fikspunkt9(x):
    count = 0
    # tester funksjonen med cos x
    for i in range(1, 1000):
        #print(x)
        xold = x        
        x = np.sqrt(np.cos(x))
        if xold == x: break
        count+=1

    return [x, count]


def newtons9a(x):
    count = 0
    # tester funksjonen med cos x
    for i in range(1, 1000):
        #print(x)
        xold = x        
        x = x - (np.sqrt(np.cos(x))-x)/(1/(2*np.sqrt(np.cos(x)))*(-np.sin(x))-1)
        if xold == x: break
        count+=1

    return [x, count]

def newtons9b(x):
    count = 0
    # tester funksjonen med cos x
    for i in range(1, 1000):
        #print(x)
        xold = x        
        x = x - ((np.cos(x)/x)-x)/(-1*(np.sin(x)*x+np.cos(x))/(x**2))
        if xold == x: break
        count+=1

    return [x, count]


print(f' Opg9 Fikspunkt: {fikspunkt9(1)} ')
print(f' Opg9 Newtons a: {newtons9a(1)} ')
print(f' Opg9 Newtons b: {newtons9b(1)} ')

# %%
