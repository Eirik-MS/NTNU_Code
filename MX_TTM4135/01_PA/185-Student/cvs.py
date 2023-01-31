import matplotlib.pyplot as plt 
import csv 

x = []
y = []

with open(input("enter CVS file name"), "r") as csvfile:
    plots = cvs.reader(cvsfile, delimiter = ",")

    for row in plots:
        x.append(row[0])
        y.append(int(row[2]))

plt.bar(x,y,color = "g")
plt.show
