def geo_rekke(r,tol):

    summ = 0
    n = 0
    while True:
        summ += r**n
        n += 1
        if r**n < tol:
            break   
    return summ

print(geo_rekke(0.5,0.0000001))