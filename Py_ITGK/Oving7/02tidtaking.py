import numpy as np
from time import perf_counter
import random
import timeit


def compare_time():
    list1 = []
    for i in range(1000000):
        list1.append(i)
    nparray = np.array(list1)
    start = perf_counter()
    dividable = []
    for j in list1:
        if j%7 == 0:
            dividable.append(j)

    end = perf_counter()
    print(f"the time for the python-list is {end-start}")

    start = perf_counter()
    dividable = nparray[nparray%7==0]
    end = perf_counter()
    print(f"the time for the numpy-array is {end-start}")


def compare_sort_time(): 
    setup = """
import random
import numpy as np
list1 = []
for i in range(1000000):
    list1.append(random.randint(0,1000000))
nparray = np.array(list1)
    """

    kode1 = """
sorted_list = sorted(list1)
    """ 

    kode2 = """
sorted_array = np.sort(nparray)
    """

    kode3 = """
sorted_list2 = list1.sort()
    """

    timekode1 = timeit.timeit(kode1, setup, number=1)
    timekode2 = timeit.timeit(kode2, setup, number=1)
    timekode3 = timeit.timeit(kode3, setup, number=1)

    print(f"the time for the python-list is {timekode1}")
    print(f"the time for the numpy-array is {timekode2}")
    print(f"the time for the python-list.sort() is {timekode3}")
    

compare_time()
compare_sort_time()