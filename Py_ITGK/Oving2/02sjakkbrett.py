def farge_på_posisjon(pos):
    bokstlist = ['a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']

    if len(pos) != 2:
        print("Feil input. Du må skrive akuratt to tegn\n")
        farge_på_posisjon(input("skriv inn en posisjon på formen 'a1'. \n"))
        return
    
    if pos[0] in bokstlist or  0 >= int(pos[1]) >= 9:
        print("Feil input.\nFørste tegn må være en bokstav A-H eller a-h \nAndre tegn må være et tall 1-8")
        farge_på_posisjon(input("skriv inn en posisjon på formen 'a1'. \n"))
        return


    bokstav = pos[0]                #gir variabelen bokstav verdien til første del av argumentet
    tall = int(pos[1])              #gir variabelen tall verdien til andre del av argumentet

    oddfarg1 = ['a', 'c', 'e', 'g', 'A', 'C', 'E', 'G']
    if tall % 2 == 0:
        if bokstav in oddfarg1:
            print("Hvit rute")
        else: print("Sort rute")
    else:
        if bokstav in oddfarg1:
            print("Sort rute")
        else: print("Hvit rute")
        return
  
farge_på_posisjon(input("skriv inn en posisjon på formen a1."))