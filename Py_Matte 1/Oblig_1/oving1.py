
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
        if xold == x: break
        count+=1

    return [x, count]
        
def diodelov(x):
    count = 0
    k = 1.380649e-23
    q = 1.60217663e-19
    T = 300
    VT = (k*T)/(q)
    # tester funksjonen med cos x
    for i in range(1, 200):
        #print(x)
        xold = x        
        x = 1- VT*np.log(x+1)
        if xold == x: break
        count+=1

    return [x, count]

valg = int(input("F = 1, N = 2, D = 3\n"))

if valg == 1:
    print(fikspunkt(int(input("Start \n"))))
elif valg ==2:
    print(newtons(int(input("Start \n"))))
elif valg == 3:
     print(diodelov(int(input("Start \n"))))
else: 
    print("velg et tall mellom 1 og 3")