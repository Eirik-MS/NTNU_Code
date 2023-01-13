telefonnummer1 = 12345678
landskode1 = 47

telefonnummer2 = 87654321
landskode2 = 46

banan = [1, 1.5, 2, 2.5, 3]
skalar = 2

a = '1'
b = True
c = False
d = '1.5'
e = '2,45'


def legg_sammen_to_tall(a, b):
    return a+b


def legg_til_landskode(telefonnummer, landskode):
    return f"+{landskode} {telefonnummer}"


def konverterINT(noe):
    return int(float(noe))


def mulipliser(l, s):
    nyliste = []
    for x in l:
        nyliste.append(x* s)
    return nyliste

print(mulipliser(banan,skalar))
print(f'a er nå {konverterINT(a)}')
print(f'b er nå {konverterINT(b)}')
print(f'c er nå {konverterINT(c)}')
print(f'd er nå {konverterINT(d)}')
print(f'e er nå {konverterINT(e)}')

print(legg_til_landskode(telefonnummer1, landskode1))
print(legg_til_landskode(telefonnummer2, landskode2))

legg_sammen_to_tall(10, 15)
