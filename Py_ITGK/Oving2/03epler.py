#%% Deler opp i celler

def teste_gavmildhet(antall_epler, antall_gis_bort):
    
    streng = "Dette er et program for å teste din sjenerøsitet.\n"
    streng += f"Du har {antall_epler} epler.\n"
    
    if antall_epler == 0:
        streng += "Æsj, det sier du bare for å slippe å gi noe!"
        return streng
    else:
        streng += f"Du er villig til å gi meg {antall_gis_bort} epler.\n"
        
        
    if antall_gis_bort < antall_epler / 2:
       streng += "Du beholder det meste for deg selv...\n"
    else:
        streng += "Takk, det var snilt!\n"
    if antall_epler - antall_gis_bort ==1:
        streng += f"Du har nå {antall_epler - antall_gis_bort} eple igjen."
    elif antall_gis_bort > antall_epler:
        streng += f"Du har nå 0 epler igjen. Gi meg de {abs(antall_gis_bort - antall_epler)} eplene du syklder meg neste gang vi møtes."
    else:
        streng += f"Du har nå {antall_epler - antall_gis_bort} epler igjen."
    
    
    return streng

print(teste_gavmildhet(12,5))
print(teste_gavmildhet(12,10))
print(teste_gavmildhet(5,7))