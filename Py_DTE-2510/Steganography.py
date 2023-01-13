

from pydoc import plain
from PIL import Image


def encodeIMG():
    plaintxt = input("\nPlease input the text you want encoded:\n")
    encoded = []
    for x in plaintxt:
        bin = format(ord(x), 'b')
        encoded.append(bin)
    print(encoded)
    IMG = Image.open(input("\nPlease input file name for image: \n"), 'r')
    img_width = IMG.width
    img_height = IMG.height
    pix_val_list = list(IMG.getdata())
    print(pix_val_list)
    print(IMG.getbands())
    
    for bin_index in range(len(encoded)):
        work_pix_arr = []
        work_pix_flat =[]
        #print(bin_index)
        
        
        work_pix_arr.append(pix_val_list[3*bin_index])
        work_pix_arr.append(pix_val_list[3*bin_index+1])
        work_pix_arr.append(pix_val_list[3*bin_index+2])
        #print(work_pix_arr)
        
        # 
        # You may think you know what the following code does.
        # But you dont. Trust me.
        # Fiddle with it, and you'll spend many a sleepless
        # night cursing the moment you thought youd be clever
        # enough to "optimize" the code below.
        # Now close this file and go play with something else.
        # 
        
        for sublist in work_pix_arr:
            for data in sublist:
                work_pix_flat.append(data)
        print(work_pix_flat)
        
        
        #Optimaliser på et senere tidspunkt
        a = 0
        for bin_one in encoded[bin_index]:
            if int(bin_one) == 0:
                if (work_pix_flat[a] % 2) != 0:
                    if work_pix_flat[a] == 255:
                        work_pix_flat[a] = work_pix_flat[a] - 1
                    else:
                        work_pix_flat[a] = work_pix_flat[a] + 1
                    
            else:
                if (work_pix_flat[a] % 2) == 0:
                    if work_pix_flat[a] == 0:
                        work_pix_flat[a] = work_pix_flat[a] + 1
                    else:
                        work_pix_flat[a] = work_pix_flat[a] - 1
            a = a +1
            
        
        if bin_index == len(encoded)-1:
            if (work_pix_flat[-1] % 2) == 0:
                if work_pix_flat[-1] == 255:
                    work_pix_flat[-1] = work_pix_flat[-1] - 1
                else:
                     work_pix_flat[-1] = work_pix_flat[-1] + 1
        else:
            if (work_pix_flat[-1] % 2) == 0:
                    if work_pix_flat[-1] == 0:
                        work_pix_flat[-1] = work_pix_flat[-1] + 1
                    else:
                        work_pix_flat[-1] = work_pix_flat[-1] - 1
        
        
        
        print("Arr: ", work_pix_arr)        
        work_pix_arr = []
        for i in range(0, 9, 3):
            work_pix_arr.append(tuple(work_pix_flat[i:i+3]))  
        print("Tuple: ", work_pix_arr)
        
        for y in range(3): pix_val_list[3*bin_index + y] = work_pix_arr[y]
        
    print(pix_val_list)
    
    #Lag nytt bilde, fortsett her.....
    newimg = Image.new("RGB", (img_width, img_height), pix_val_list)  
    newimg.save("encode")
                
    
    return pix_val_list



def main ():
    print("Steganography.py is a program that encodes text into picture")
    choise = input("1. Encode \n2. Decode\n")
    if choise == "1":
        aary = encodeIMG()

    elif choise == "2":
        pass
    else:
        main()
        print("please enter a number between 1 and 2")
        return 0
    
    
main()