from turtle import color
import numpy as np
import matplotlib.pyplot as plt

file_poeng = np.loadtxt("./Jupyter/Poenggrenser.txt")
file_aar = np.loadtxt("./Jupyter/År.txt")


def min_max_score(operation):
    match operation:
        case "min":
            min = file_poeng[0]
            aar = file_aar[0]
            for i in range(len(file_poeng)):
                if file_poeng[i] < min:
                    min = file_poeng[i]
                    aar = file_aar[i]
            return aar, min
        case "max":
            max = file_poeng[0]
            aar = file_aar[0]
            for i in range(len(file_poeng)):
                if file_poeng[i] > max:
                    max = file_poeng[i]
                    aar = file_aar[i]
            return aar, max
        case _:
            return -1



def min_max_score_numpy(operation):
    match operation:
        case "min":
            min = np.min(file_poeng)
            aar = file_aar[np.argmin(file_poeng)]
            return aar, min
        case "max":
            max = np.max(file_poeng)
            aar = file_aar[np.argmax(file_poeng)]
            return aar, max
        case _:
            return -1

min =min_max_score_numpy("min")
max =min_max_score_numpy("max")
plt.plot(file_aar, file_poeng)
plt.scatter(min[0], min[1], color = "red")
plt.scatter(max[0], max[1], color = "red")
plt.xlabel("År")
plt.ylabel("Poenggrense")
plt.title("Poenggrenser for å komme inn på NTNU")
plt.show()