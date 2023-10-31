##Find center hole diviation from ideal position
import numpy as np
ideal_position = [40,30,0]
hole_position = [40.14, 30.15, 0]

#Calculate diviation
diviation = [ideal_position[0]-hole_position[0],ideal_position[1]-hole_position[1]]

#calculate center position change
pos_change = np.sqrt(diviation[0]**2+diviation[1]**2)

#Print diviation
print(diviation) #0.14, -0.15
print(pos_change) #0.205
 