import random

randliste = []
for i in range(100):
    randliste.append(random.randint(0, 10))

print(randliste.count(2))
print(sum(randliste))
print(randliste.sort())

def typetall(liste):
    count = 0
    tall = 0
    for i in range(10):
        if randliste.count(i) > count:
            count = randliste.count(i)
            tall = i

    return tall,count

print(typetall(randliste))

print(randliste.reverse())
        

