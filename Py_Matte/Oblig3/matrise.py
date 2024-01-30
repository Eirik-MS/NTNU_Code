bintall = [0,0,1,1,1,0,1,1,1,0,0,1,0,1,0,0]
spenning = 0
n = 1

for i in range(len(bintall)):
    if bintall[i]:
        spenning += 5/2**n
    n += 1

print(bintall)
print(spenning)
