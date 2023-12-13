import numpy as np

Q = 10
F_0 = 3000
C = 1e-8 #Bruk smaa kondensatorar
H_0 = 1 #Hvor høg amplituden skal være i F_0

print(f'Med en Q på {Q}, og en resonansfrekvens på {F_0} Hz velger vi C = {C:.3E} og en maksamplitdude H_0 = {H_0}. Da faar vi:')

R3 = Q/(np.pi*F_0*C)
R1 = R3/(2*H_0)
R2 = R3/(4*Q*Q - 2*H_0)
print(f'R3 = {R3:.3E}')
print(f'R1 = {R1:.3E}')
print(f'R2 = {R2:.3E}')
