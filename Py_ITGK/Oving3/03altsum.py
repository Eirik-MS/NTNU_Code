
def alt_sum(n):
    summen = 0
    
    for i in range(n+1):
        if i % 2 == 0:
            summen -= i**2
        else:
            summen += i**2
            
    return summen
            
            
def alt_sum2(n):
    summen = 0 
    itterasjon = 0
    
    for i in range(n+1):
        if summen >= n:break
        print(summen,itterasjon, n)
        
        if itterasjon % 2 == 0:
            summen -= i**2
        else:
            summen += i**2
        itterasjon += 1
    return summen, itterasjon

    
            
#print(alt_sum(7))
print(alt_sum2(6))
        