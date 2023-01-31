def everyfourth(string):
    return string[::4]

def lastTwo_inList(list):
    newStr = ""
    for i in list:
        newStr += i[-2:]
    return newStr


#Kodesnutt 1
streng = "I Want Cake"
streng = streng[7:] +"Cupcake"
print(streng)
 
#Kodesnutt 2
streng = "I Want Cake"
streng = streng[-4:100:] 
print(streng)
 
#Kodesnutt 3
streng = "I Want Cake"
streng = streng[3] #mangler index i koden
print(streng)