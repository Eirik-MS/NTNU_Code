import numpy as np


def fikspunkt(x):
    count = 0
    # tester funksjonen med cos x
    for i in range(1, 200):
        #print(x)
        xold = x        
        x = np.cos(x)
        if xold == x: break
        count+=1

    return [x, count]

def newtons(x):
    count = 0
    for i in range(1, 200):
        xold = x
        x = x + ((np.cos(x)-x)/(np.sin(x)+1))
        if xold == x:break
        count+=1

    return [x, count]
        

svar1 = fikspunkt(np.pi/4)
svar2 = newtons(np.pi/4)

svar3 = fikspunkt(-10)
svar4 = newtons(-10)

print(f' Opg2 Fikspunk: {svar1[0]} with {svar1[1]} iterations')
print(f' Opg2 Newtons: {svar2[0]} with {svar2[1]} iterations')
print(f' Opg2 Fikspunk: {svar3[0]} with {svar3[1]} iterations')
print(f' Opg2 Newtons: {svar4[0]} with {svar4[1]} iterations')