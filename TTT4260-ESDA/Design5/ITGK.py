
def geo_rekke(utrykk, toleranse):
    summ = 0
    n = 0
    forskjell = toleranse+1

    while forskjell > toleranse:
        gammel_summ = summ
        summ += utrykk**n
        forskjell = summ - gammel_summ
        n += 1
    return summ

#print(geo_rekke(0.5, 0.00001))



##%%%###
import math 

def pi(d = 2):
    if d > 15:
        return "Error: d must be less than 15"
    else:
        return round(math.pi, d)
    

print(pi(16))
print(pi(15))
print(pi(4))
print(pi())