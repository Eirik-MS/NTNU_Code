import random

def myGuess_inp():
    numbers = []
    for i in range(1,34): numbers.append(i)

    inpstr = input("please enter your guesses with a space in between:\n")
    liststr = inpstr.split()
    guesslist = []

    for i in liststr:
        i = int(i)
        guesslist.append(i)

    return numbers, guesslist

def drawNumbers(numbers,n):
     drawnlist=[]
     for i in range(n):
        randomint = random.randint(0,numbers[-1]-1)
        drawnnum = numbers[randomint]
        drawnlist.append(drawnnum)
        numbers.pop(randomint)
        
        return drawnlist

def compList(list1, list2):
    count = 0
    for i in list1:
        if i in list2:
            count += 1
    return count

def Winnings(num,bonus):
    match num:
        case 4: 
            if bonus==1: return 45
        case 5: 
            return 95
        case 6:
            if bonus==1: return 102110
            else: return 3385
        case 7:
            return 2749455

def main():
    numbers, guesslist = myGuess_inp()
    drawnlist = drawNumbers(numbers,7)
    bonus = drawnlist.pop(6)
    print(f"the drawn numbers are: {drawnlist} and the bonus is {bonus}")
    print(f"your guesses were: {guesslist}")
    num = compList(drawnlist,guesslist)
    print(f"you guessed {num} numbers correctly")
    if num >= 4:
        print(f"you won {Winnings(num,bonus)} NOK")
    else:
        print("you lost")
    return 0
    

main()