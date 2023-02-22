
#
import numpy as np

print(np.sqrt(1%95))


#find i with for loops

for i in range(3, 1000):
    d_1 = i % 10
    d_2 = i % 16
    
    if d_1 == d_2 == 9:
        print("d_1 : "+ str(d_1) +" d_2 :" +str(d_2) + " and i =" + str(i))
        