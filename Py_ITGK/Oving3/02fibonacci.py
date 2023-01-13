

def fibonacci(itterasjon):

    f1 = 0
    f2 = 1
    
    
    for i in range(itterasjon):
        f3 = f1 + f2
        print(f'{f1}')
        f1 = f2
        f2 = f3
    

def fibonacci_sum(itterasjon):

    f1 = 0
    f2 = 1
    summen = 0
    
    for i in range(itterasjon):
        summen += f1
        f3 = f1 + f2
        print(f'({f1}, {summen})')
        f1 = f2
        f2 = f3


def fibonacci_liste(itterasjon):
    itterasjon -= 2
    f = [0,1]
    
    for i in range(itterasjon):
        f.append(f[i] + f[i+1])
        
    
    return f
    
    
    
fibonacci(10)
fibonacci_sum(10)
print(fibonacci_liste(10))
