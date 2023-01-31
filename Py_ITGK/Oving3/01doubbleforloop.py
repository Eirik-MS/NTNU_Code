

def talltrekant(num):
    print(f'Talltrekant: {num}')
    num = num + 1
    for i in range(1 ,num, 1):
        for j in range(1, i+1):
            print(j, end="")
        print()
    return
        


def xtrekant(num):
    print(f'Xtrekant: {num}')
    for i in range(1, num):
        print('X', end="")
        for j in range(1, i+1):
            print(" ", end="")
    return 



def primenumbers(num):
    print(f'Prime numbers: {num}')
    numold = num
    faktors = []
    string = ""
    
    for i in range(2, numold + 1):
        ### Finner faktorer med while istedenfor, blir penere og et smartere valg enn for loop med if statements
        while num % i == 0:
            faktors.append(i)
            num = num / i
        '''
        if num % i == 0:
            for j in range(numold):
                faktors.append(i)
                num = num / i
                if num % i != 0:
                    break
        '''
    
    if len(faktors) == 1:
        print(f'{numold} is prime')
    else:
        for x in faktors: string += str(x) + "*"
        string = string[:-1] + " "
        print(f'{string}is the prime factorization of {numold}')
    
    return faktors


def testGanngetabell():
    liv = 3
    tall1 = 0
    tall2 = 0
    summen = tall1 + tall2
    
    


#talltrekant(5)
#xtrekant(5)
primenumbers(1000)