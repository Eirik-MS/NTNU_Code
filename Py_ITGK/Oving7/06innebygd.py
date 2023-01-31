#%%

fruit = {'apple': 2, 'banana': 3, 'pear': 5, 'orange': 1}

del fruit['pear']
del fruit['orange']

fruit['cinamon'] = 7

print(fruit['cinamon'])

if 'banana' in fruit:
    del fruit['banana']

print(fruit)

