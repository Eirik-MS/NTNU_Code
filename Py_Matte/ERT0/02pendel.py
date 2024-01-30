


#%%% Oppgave 1 Av Eirik
import numpy as np
import matplotlib.pyplot as plt

T = 10
N = 5000
h = T/N

g1 = 9.81
l = 1

x = np.zeros(N+1)
y = np.zeros(N+1)
t = np.zeros(N+1)

x[0] = 0.1
y[0] = 2

def f(x, y):
    return y

def g(x, y):
    return -(g1/l) * np.sin(x)

for i in range(N): 
    x[i+1] = x[i] + h * f(x[i], y[i])
    y[i+1] = y[i] + h * g(x[i], y[i])
    t[i+1] = t[i] + h
        

axe = plt.figure().add_subplot(1, 1, 1)
axe.spines['bottom'].set_position('zero')
axe.spines['right'].set_color('none')
axe.spines['top'].set_color('none')
axe.xaxis.set_ticks_position('bottom')
axe.yaxis.set_ticks_position('left')

#plt.plot(t,x, label='x(t)')
plt.plot(t,y, label='y(t)')
plt.show()

#%%% Oppgave 2 Fra nettet
# Importing libraries

import math
import numpy as np
from scipy.integrate import solve_ivp
import matplotlib.pyplot as plt
import os

# Initial and end values
st = 0          # Start time (s)
et = 10       # End time (s)
ts = 0.1        # Time step (s)
g = 9.81        # Acceleration due to gravity (m/s^2)
L = 1           # Length of pendulum (m)
b = 0.2        # Damping factor (kg/s)
m = 1           # Mass of bob (kg)


# 1st order equations to solve in a function


"""
 theta1 is angular displacement at current time instant
 theta2 is angular velocity at current time instant
 dtheta2_dt is angular acceleration at current time instant
 dtheta1_dt is rate of change of angular displacement at current time instant i.e. same as theta2 
"""

def sim_pen_eq(t,theta):
		dtheta2_dt = (-b/m)*theta[1] + (-g/L)*np.sin(theta[0])
		dtheta1_dt = theta[1]
		return [dtheta1_dt, dtheta2_dt]



# main

theta1_ini = 0                 # Initial angular displacement (rad)
theta2_ini = 3                 # Initial angular velocity (rad/s)
theta_ini = [theta1_ini, theta2_ini]
t_span = [st,et+ts]
t = np.arange(st,et+ts,ts)
sim_points = len(t)
l = np.arange(0,sim_points,1)

theta12 = solve_ivp(sim_pen_eq, t_span, theta_ini, t_eval = t)
theta1 = theta12.y[0,:]
theta2 = theta12.y[1,:]
plt.plot(t,theta1,label='Angular Displacement (rad)')
plt.plot(t,theta2,label='Angular velocity (rad/s)')
plt.xlabel('Time(s)')
plt.ylabel('Angular Disp.(rad) and Angular Vel.(rad/s)')
plt.legend()
plt.show()



# Simulation

x = L*np.sin(theta1)
y = -L*np.cos(theta1)


for point in l:
		plt.figure()
		plt.plot(x[point],y[point],'bo',markersize=20)
		plt.plot([0,x[point]], [0,y[point]])
		plt.xlim(-L-0.5,L+0.5)
		plt.ylim(-L-0.5,L+0.5)
		plt.xlabel('x-direction')
		plt.ylabel('y-direction')
		filenumber = point
		filenumber=format(filenumber,"05")
		filename="image{}.png".format(filenumber)
		plt.savefig(filename)
		plt.close()
# %%
