from datetime import datetime
import random

def summerOlympics(firstYear, lastYear):
    years =[]
    for i in range(firstYear,lastYear+1):
        if i % 4 == 0:
            years.append(i)
    
    return years

print(summerOlympics(1999,2022))

def current_date():
    yyyy = int(datetime.today().strftime('%Y'))
    mm = int(datetime.today().strftime('%m'))
    dd = int(datetime.today().strftime('%d'))
    return yyyy,mm,dd

def findAge(bYear, bMont,bDay):
    date = current_date()
    print(date)
    age = date[0]-(bYear+1)
    if bMont <= date[1] and bDay <= date[2]:
        age +=1

    return age

print(findAge(2000,12,5))

def printAgeDiff(table):
    for i in range(len(table)-1): 
        age = findAge(table[i][2], table[i][3], table[i][4])
        next_age= findAge(table[i+1][2], table[i+1][3], table[i+1][4])
        if age == next_age:
            print(f'{table[i][0]} {table[i][1] } is at the same age as {table[i+1][0]} {table[i+1][1]}')
        elif age < next_age:
            print(f'{table[i][0]} {table[i][1] } is younger than {table[i+1][0]} {table[i+1][1]}')
        else:
            print(f'{table[i][0]} {table[i][1] } is older than {table[i+1][0]} {table[i+1][1]}')

table=[['Justin','Bieber',1994,3,1],
       ['Donald','Duck',1934,8,1],
       ['George','Clooney',1961,5,6],
       ['Eddie','Murphy',1961,4,3]]

printAgeDiff(table)

def cold_days(templist):
    days = 0
    for elmt in templist:
        if elmt < 0:
            days += 1
    return days

print(cold_days([1,-5,3,0,-6,-3,15,0]))

def cap_data(array, min_value, max_value):
    for i in range(len(array)):
        if array[i] < min_value:
            array[i] = min_value
        elif array[i] > max_value:
            array[i] = max_value

    return array

def genreate_testdatasom(N, min_value, max_value):
    resault = []
    for i in range(N):
        a = random.randint(min_value,max_value)
        while a in resault:
            a = random.randint(min_value,max_value)
        resault.append(a)
    return resault

print(genreate_testdatasom(10, -20, 20))

def create_db(temp, rain, humidity, wind):
    weather = {}
    for i in range(len(temp)):
        weather[i+1]=[temp[i], rain[i], humidity[i], wind[i]]

    return weather

def print_db(wether):
    print('Day | Temp | rain | humidity | wind')
    print('====+======+======+==========+======')
    ind4 = 4
    ind6 = 7
    ind10 = 11
    ws = ' '
    for key, value in wether.items():
        print(f'{(ind4-len(str(key)))*ws}{key}',end = '')
        print(f'{(ind6-len(str(value[0])))*ws}{value[0]}',end = '')
        print(f'{(ind6-len(str(value[1])))*ws}{value[1]}',end = '')
        print(f'{(ind10-len(str(value[2])))*ws}{value[2]}',end = '')
        print(f'{(ind6-len(str(value[3])))*ws}{value[3]}')
        
        pass
print_db({1: [1, 0, 30, 3], 2: [5, 30, 50, 5], 3: [3, 120, 65, 7]})

a = input("Text")
a = "Jonas"
a = "" or 1 == 1 or ""

if a == "Jonas":
    print_db()
