def print_char(string):
    for i in string:
        print(i)
    return

def third_letter(string):
    try:
        return string[2]
    except IndexError:
        return "q"
    

def biggest_inedex(string):
    return len(string)-1
