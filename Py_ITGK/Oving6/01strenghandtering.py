def check_equal(str1,str2):
    index = 0
    for i in str1:
        if i != str2[index]: return False
        index += 1
    return True

def contain_string(str1, str2):
    if str2 in str1:
        for i in range(len(str1)):
            if str1[i] == str2[0]:
                for j in range(len(str2)):
                    if str1[i+j] != str2[j]:
                        break
                    else:
                        print(str1[i+j])
    else:
        return -1
    
    
    count_str1 = 0
    len_str2 = len(str2)
    for bokstav in str1:
        if bokstav == str2[0]:
            compare1 = ""
            for k in range(len_str2):
                compare1 += str1[k+count_str1]
            check_equal(compare1, str2)
        count_str1 += 1



#check_equal("hei og ", "hade")

str3 = "heiMitt"
str4 = "Mi"

print(contain_string(str3,str4))