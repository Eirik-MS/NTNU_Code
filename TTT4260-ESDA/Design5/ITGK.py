
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

print(geo_rekke(0.5, 0.00001))

intr = int(input("halla"))
print(intr)