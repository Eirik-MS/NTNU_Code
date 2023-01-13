def no_common_letters(L):
    nocList = []
    for elmt in L:
        if not any(i in elmt[0].lower() for i in elmt[1].lower()):
            nocList.append([elmt[0], elmt[1]])
    return nocList
        
"""
for i in elmt[0].lower():
    print(i)
    if i in elmt[1].lower():
        break
else:
    nocList.append(elmt)
"""
##nocList.append([elmt[0], elmt[1]]) if not any(i in elmt[0].lower() for i in elmt[1].lower()) else None


def unique_letters(lst):
    dict_capitals = {}
    for elmt in lst:
        if not any(elmt[1].lower().count(letter) > 1 for letter in elmt[1].lower()):
            if len(elmt[1]) in dict_capitals:
                dict_capitals[len(elmt[1])].append(elmt[1])
            else:
                dict_capitals[len(elmt[1])] = [elmt[1]]
    return dict_capitals

def id_matrix(num):
    matrix = []
    for i in range(num):
        list = []
        for j in range(num):
            list.append(0)
        list[i]=1
        matrix.append(list)
    return matrix

L = [
    ["China", "Beijing", 5],
    ["Norway", "Oslo", 5],
    ["USA", "Washington", 7],
    ["India", "New Delhi", 9],
    ["Egypt", "Cairo", 100],
]

print(id_matrix(5))

def myst(a):
    b=[]
    while len(a)>0:
        c=a[0]
        for i in a:
            if i < c:
                c=i
        a.remove(c)
        b.append(c)
    return b

print(myst([99,17,65,19,82]))