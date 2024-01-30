##Solving partiall differential equation using numerical methods

import numpy as np

#Task one

def f1(x):
    return np.e**x

def derivate(f, x, h):
    return (f(x+h)-f(x))/h

def derivativeV2(f, x, h):
    return (f(x+h)-f(x-h))/(2*h)

def derivativeV3(f, x, h):
    return (f(x-2*h) - 8*f(x-h) + 8*f(x+h) - f(x+2*h))/(12*h)

def proof_of_derivative(f, x, n):
    start = 0.1
    listofsul = []
    acc = []
    answer = np.e**x
    print("f(x) = e^x\nDerivative of f(x) with decrease of h")
    print("  ","{:<12s} {:<15s} {:<15s} {:<15s} {:<15s} {:<15s} {:<15s}".format("h", "derivative", "derivative2", "derivative3", "accuracy", "accuracy2", "accuracy3"))
    for i in range(n):
        h = start / (10**i)
        derivative = derivate(f, x, h)
        derivative2 = derivativeV2(f, x, h)
        derivative3 = derivativeV3(f, x, h)
        accuracy = abs(answer - derivative)
        accuracy2 = abs(answer - derivative2)
        accuracy3 = abs(answer - derivative3)
        listofsul.append(derivative)
        acc.append(accuracy)
        print(f"{i} ", "{:<10.10f} {:<15.10f} {:<15.10f} {:<15.10f} {:<15.10f} {:<15.10f} {:<15.10f}".format(h, derivative, derivative2, derivative3, accuracy, accuracy2, accuracy3))
        
proof_of_derivative(f1, 1.5, 10)

#Now that we have the derivative we can use it to solve the partial differential equation 
#For the heat equation we have u(0,t) = u(1,t) = 0 and u(x,0) = f(x)

def u_t(xi, t):
    return 

def u_xx(xi, t):
    return

def soving_heat(f, h, k):
    
    xAxis = np.arrange(0, 1, h)
    tAxis = np.arrange(0, 1, k)
    
    