import binascii
import random
import string

 
def toHex(word):
    #gjør om fra textstreng til heltall
    return int(str(binascii.hexlify(word), 'ascii'), 16)
 
def toString(word):
    #gjør om fra heltall til textstreng igjen
    return str(binascii.unhexlify(hex(word)[2:]), 'ascii')


def encrypt(message, key):
    #skjekker om nøkkelen er lang nok
    if len(message) != len(key):
        return "Error: message and key must be of equal length"
    message = toHex(bytes(message, 'ascii'))
    key = toHex(bytes(key, 'ascii'))
    code = message ^ key
    return code

def decrypt(code, key):
    key = toHex(bytes(key, 'ascii'))
    message = code ^ key
    return toString(message)

def main():
    message = input("Enter message: ")
    key = ""
    for i in range(len(message)):
        key += random.choice(string.ascii_letters)
    code = encrypt(message, key)
    print(code)
    print(decrypt(code, key))

main()