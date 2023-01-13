import numpy as np
import matplotlib.pyplot as plt
import csv


with open("winequality-red.csv", 'r') as f:
    wines = list(csv.reader(f, delimiter=";"))

WINE_PARAMETERS = wines[0]
WINES = np.array(wines[1:], dtype=float)

print(f"Parametre: {WINE_PARAMETERS}")
print(f"Størrelse på WINES: {WINES.shape}")

def get_wine_index(parametres):
    try:
        indexof = WINE_PARAMETERS.index(parametres)
        print(f"index of {indexof}")
        return indexof
    except:
        print("Fant ikke parameteren")
        return None
    

def create_Analysis_dict(nokkel_parameter, verdi_parameter):
    analysis_dict = {}
    nokkel_index = get_wine_index(nokkel_parameter)
    verdi_index = get_wine_index(verdi_parameter)


    for index in range(len(WINES)):
        nokkel = WINES[index][nokkel_index]
        verdi = WINES[index][verdi_index]
        if nokkel in analysis_dict:
            analysis_dict[nokkel].append(verdi)
        else:
            analysis_dict[nokkel] = [verdi]

    return analysis_dict

def simple_statistic(dictionary):
    stat_arr = []
    for key, value in dictionary.items():
        minimum = min(value)
        maximum = max(value)
        average = sum(value)/len(value)
        stat_arr.append(np.array([key, average, maximum, minimum]))
    return np.array(stat_arr)

def show_plot(parameter1, parameter2):
    dict = create_Analysis_dict(parameter1,parameter2)
    resualt = simple_statistic(dict)
    sorted_resualt = resualt[:, 0].argsort()
    sorted_resualt = resualt[sorted_resualt, :]
    key, min, max, avrg = [], [], [], []
    for i in sorted_resualt:
        key.append(i[0])
        min.append(i[1])
        max.append(i[2])
        avrg.append(i[3])

    y = np.vstack([min, avrg, max])

    fig, ax = plt.subplots()

    plt.plot(key,min)
    plt.plot(key, max)
    plt.plot(key,avrg)

    plt.show()


    


show_plot("alcohol", "pH")
print(WINES)
