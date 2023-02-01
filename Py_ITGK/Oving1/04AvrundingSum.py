import math
import numpy


T = 3.1e11 # et stort tall
t = 3.1e-5 # et lite tall

# Liste med stort tall fremst, bruker Pythons standard sum-funksjon
L = [T,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t,t]
print(len(L))
print(f'Standard sum(): {sum(L)}')

# Numpy array, stort tall fremst, np.sum() funksjon
A = numpy.array(L)
print(f'Numpy sum(): {numpy.sum(L)}')

# math.fsum() funksjonen
print(f'Math fsum(): {math.fsum(L)}')

#Math fsum er nok best å bruke ettersom det er mest nøyaktig