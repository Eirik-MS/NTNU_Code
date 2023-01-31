#Jacobis Itteration

import numpy as np
import matplotlib.pyplot as plt


A = [[3,1,1],[1,3,1],[1,1,3]]
b = [1,1,1]
D = np.diag(np.diag(A))
D_inv = np.linalg.inv(D)

def matrix_subtract(A,B):
    return [[A[i][j] - B[i][j] for j in range(len(A[0]))] for i in range(len(A))]

def matrix_multiply(A,B):
    return [[sum(a*b for a,b in zip(A_row,B_col)) for B_col in zip(*B)] for A_row in A]

def vector_subtract(A,B):
    return [A[i] - B[i] for i in range(len(A))]

def vector_matrix_multiply(A,B):
    return [sum(a*b for a,b in zip(A_row,B_col)) for B_col in zip(*B) for A_row in A]

def Jacobi(A,b,x0):
    D = np.diag(np.diag(A))
    D_inv = np.linalg.inv(D)
    R = matrix_subtract(A,D)
    x = np.zeros_like(b)
    x0 = np.zeros_like(b)
    for i in range(100):
        x = vector_subtract(x0,vector_matrix_multiply(D_inv,R))
        x0 = x
    return x

print(Jacobi(A,b,0))