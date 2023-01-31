

def kake_ut_av_ovnen(tid):
    print(f"Kaken har vært i ovnen i {tid} minutter.")
    if tid >= 50:
        print("Kaken kan tas ut av ovnen.")
    print("Tips til servering: vaniljeis.")
    print("----------------------------------------")





def antall_epler_per_barn(epler, barn):
    if barn == 0: 
        print("Takk for i dag!")
        return 0
    
    # Antall epler til hvert barn
    antall_per = epler // barn
    # Antall epler det er igjen etter at barna har fått sine epler
    antall_rest = epler % barn
    print("Da blir det", antall_per, "epler til hvert barn")
    print("og", antall_rest, "epler til overs til deg selv.")
    print("Takk for i dag!")

    return antall_per, antall_rest


def kan_stemme(alder):
    if alder >= 18:
        print("Du kan stemme både ved lokalvalg og stortingsvalg :)")
    elif alder >= 16:
        print("Kan stemme ved lokalvalg, men ikke ved stortingsvalg")
    else:
        print("Du kan ikke stemme enda")


def bliettpris(alder):
    if alder < 3:
        print("Gratis")
    elif alder <11:
        print("30kr")
    elif alder < 25:
        print("50kr")
    elif alder <66:
        print("80kr")
    elif alder < 67:
        print("40kr")


kake_ut_av_ovnen(10)
kake_ut_av_ovnen(60)

antall_epler_per_barn(12,5)
antall_epler_per_barn(3,0)

