def tooth_fairy(teeth):
    listwithall = []
    for i in teeth:
        amount_coins = []
        coins= [20,10,5,1]
        for j in coins:
            if i >= j:
                number = i //j
                amount_coins.append(number)
                i = i - (number*j)
            else:
                amount_coins.append(0)  
        listwithall.append(amount_coins)
    return listwithall

print(tooth_fairy([53,28]))

def 