import random

def random_matrise(kolonner, rader):
    matrise = []
    for i in range(rader):
        kol = []
        for j in range(kolonner):
            kol.append(random.randint(0,9))
        matrise.append(kol)
        
    return matrise

def print_matrise(matrise, navn):
    print(f'{navn}= [')
    for i in range(len(matrise)):
        str = f'    ['
        for j in range(len(matrise[i])):
            lengde = len(matrise[i])-1
            if j == lengde:
                str += f'{matrise[i][j]}]'
            else: str += f'{matrise[i][j]}, '
        print(str)
    print(f'  ]')
    return


def matrise_addisjon(matriseA, matriseB):
    matriseC = []
    if len(matriseA) != len(matriseB) and len(matriseA[0]) != len(matriseB[0]):
        print('Matrisene er ikke av samme dimmensjon')
        return 0

    for i in range(len(matriseA)):
        kol = []
        #print(matriseA[i], end = " ")
        #print(type(matriseA[i]))
        for j in range(len(matriseB[i])):
            kol.append(matriseA[i][j] + matriseB[i][j])
        matriseC.append(kol)
    return matriseC


def main():
    A = random_matrise(4,3)
    B = random_matrise(3,4)
    C = random_matrise(3,4)
    

    print_matrise(A, 'A')
    print_matrise(B, 'B')
    print_matrise(C, 'C')

    D = matrise_addisjon(A,B)
    E = matrise_addisjon(B,C)
    print_matrise(E, 'B+C' )

main()

def der
