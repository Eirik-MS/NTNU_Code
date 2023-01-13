

my_family = {}

def add_family_member(role, name):
    if role in my_family:
        my_family[role].append(name)
    else:
        my_family[role] = [name]

def print_family():
    for role in my_family:
        for pearson in my_family[role]:
            print(f"{role} : {pearson}")





add_family_member('bror', 'Arne')
add_family_member('bror', 'jonatan')
add_family_member('mor', 'Anne')
add_family_member('bror', 'Geir')
print_family()