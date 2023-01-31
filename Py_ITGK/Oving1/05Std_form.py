stoff = "vann"
g = 500
molvekt = 18

def molekyler_av_stoff(g, molvekt):
    return g/molvekt * 6.02e+23


molekyler = molekyler_av_stoff(g, molvekt)

def E(v):
    return 6.626e-34*v

v = 4.29e+14
print(f'Rødt lys, som har frekvens {v:.2e}Hz, har en energi på {E(v):.2e}J')

print(f'Du har {molekyler:.1e} mokelyker {stoff}')