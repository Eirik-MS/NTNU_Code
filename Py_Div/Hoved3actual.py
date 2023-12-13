class Student:
    def __init__(self, brukernavn, epost):
        self.brukernavn = brukernavn
        self.epost = epost
        self.vurderinger = []

    def ny_vurdering(self, emne, vurdering_tekst, skår):
        vurdering = Vurdering(vurdering_tekst, skår, emne, self)
        emne.ny_vurdering(vurdering)
        self.vurderinger.append(vurdering)

    def skriv_ut(self):
        resultat = f"Navn: {self.brukernavn}, epost: {self.epost}\n"
        for vurdering in self.vurderinger:
            resultat += vurdering.skriv_ut() + "\n"
        return resultat


class Emne:
    def __init__(self, emne_kode, emne_navn):
        self.emne_kode = emne_kode
        self.emne_navn = emne_navn
        self.vurderinger = []
        self.gjennomsnittlig_vurdering = None

    def ny_vurdering(self, vurdering):
        self.vurderinger.append(vurdering)
        self.beregn_gjennomsnittlig_vurdering()

    def beregn_gjennomsnittlig_vurdering(self):
        if not self.vurderinger:
            self.gjennomsnittlig_vurdering = None
            return

        total_skår = sum(vurdering.skår for vurdering in self.vurderinger)
        antall_vurderinger = len(self.vurderinger)
        self.gjennomsnittlig_vurdering = total_skår / antall_vurderinger

    def skriv_ut(self):
        if not self.vurderinger:
            return f"Emne {self.emne_kode}: {self.emne_navn}"
        else:
            resultat = f"Emne {self.emne_kode}: {self.emne_navn}\nVurderinger:\n"
            for vurdering in self.vurderinger:
                resultat += vurdering.skriv_ut() + "\n"

            if self.gjennomsnittlig_vurdering is not None:
                resultat += f"Gjennomsnittlig vurdering: {self.gjennomsnittlig_vurdering}\n"
            return resultat


class Vurdering:
    def __init__(self, vurdering_tekst, skår, emne, student):
        self.vurdering_tekst = vurdering_tekst
        self.skår = skår
        self.emne = emne
        self.student = student

    def skriv_ut(self):
        return f"{self.student.brukernavn}, {self.emne.emne_kode}: " \
               f"\"{self.vurdering_tekst}\", skår={self.skår}"

alina = Student('Alina Farschian', 'afa754@student.uib.no')
info132 = Emne('INFO132', 'Innføring i programmering')
print(info132.skriv_ut())  

alina.ny_vurdering(info132, 'Kjempebra emne! Jeg tar det om igjen neste høst!', 5)

print(alina.skriv_ut())
print(info132.skriv_ut())

olea = Student('Olea Haldorsen', 'oha356@student.uib.no')
olea.ny_vurdering(info132, 'Sånn passe. DATA110 om våren dekker omtrent det samme.', 3)

print(olea.skriv_ut())
print(info132.skriv_ut())


