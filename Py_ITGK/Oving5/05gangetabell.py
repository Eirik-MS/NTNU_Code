def seperate(number, threshold):
    mindre = []
    større = []
    for i in number:
        if i < threshold:
            mindre.append(i)
        else:
            større.append(i)
    return mindre, større

def gangetabell(iterations):
    gangetabell = []
    for i in range(iterations):
        gangerekker =[]
        for j in range(iterations):
            gangerekker.append((i+1)*(j+1))

        gangetabell.append(gangerekker)
            
        print(gangetabell)
    return gangetabell