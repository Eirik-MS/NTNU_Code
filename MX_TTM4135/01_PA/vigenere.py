##alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-'
##
##
##vigenere_encrypted = "GHGKLDNSSA-GGZB-GXPZMPUULKDRPPSQ-BBAPGUPJGGALLVVPPYCSMCL-RLOLJV-CKJVQEGTVRZOG-QLFFRN-GPGS,GPHFPATYCLYUHMOJ,PCDZTMLZOCBBB-GB.EVKHC-XCACZMVZLLOJZRPVRFMYVPURSJGKPCWDZQSGPHML-GRNJLYCJLJIVUZEGBGYXQHRZFFFCAKGGUPJGGGBLKBEZFCSCYXJKGB-D-MZYBGKPVTVBBAPHPLQUZLQJQBRZ,VYCXVPUWPDNCUMGFZCAVEFMAKVYCTJMBCPKAHFPQYVPPHNIAVAPXRSZDZPOK-RLOLC-ITFIRQB-GMNWME.COTUIBOZP-WLXJZAVZPT.XZH-MCFFVPTFIOFLDHWJGAPXYSVNWPCFPZLRAPHMB-GGNLXGONCJUICOW,RRSATUUZECBUSGUV.RZECSWYJRPOD,SCCFFVPPAIYRGTC-RSGWXFEA.VLPYCBBCFUHCLY,CLSZT-CRKUYCVZRHS,LJVASVUVYP.IVBZFDMRSZNRSR-VVPZ,VYCZLJVPA-GFDLXGK.AZZDPPKUZTPGHWS-AQIQ-VIVYLFFRQA-GF.YKJVQEGTVGYKRRLTKJPD-AIYRPFGU-G-CBBKXNRN,APXFPJGO.YVR.GYLJVPPSVYCMATUPLFVYGAOCM.YYVY.BAPGFLJRRLRDGGYLFFWGYVN-WQDWHRPJGUQBJCZESLCHRSZQ-BEGORLIOJCM,ZPVBSZTGALFVME-Z,GITJVGRZZPTJZKGZRIYTCN,ZFINZFKHGYVDILODGO.YYVYCY-Q-BTFIZRZMVTSBAVGFPVFCDQOKHFLFGLN-ZUGGZFQWTTFFZABAXVCYZTXWLFFHPTMODFNGOSGYZFPRSZD-MZYCBBB-GIEWQYFGR.NZLR,CGATFCHCOJCTFPD-GMB-CH.WLJCSR-UYCVFGKRSVVGMXZQBCSVFTMXZWD-P-KBBLFFK.AKVRLOAPX-PKKUCSZTOQSZFZBYGVHS-FTCSYYWBRTDVYCZDFKMXVPY.OKGHRWZFUMEFQBRSZDVLN-DVQTYGHFPGVYC-KAHFPFUYCWGQ.COMRGFLJR-WIWGT.CKGCDB-GIEWAPVQAGHKFLLUYCSVFGCPFAZREVUAGAKC-JLFYYMALQCBMZUZBP"
##
### Function to decrypt the vigenere cipher
##
##periodOfKey = 5
##stream1 = []
##stream2 = []
##steram2 = []
##stream3 = []
##stream4 = []
##stream5 = []
##
##
##for i in range(len(vigenere_encrypted)):
##        if i % 5 == 0:
##                stream1.append(vigenere_encrypted[i])
##        elif i % 5 == 1:
##                stream2.append(vigenere_encrypted[i])
##        elif i % 5 == 2:
##                stream3.append(vigenere_encrypted[i])
##        elif i % 5 == 3:
##                stream4.append(vigenere_encrypted[i])
##        elif i % 5 == 4:
##                stream5.append(vigenere_encrypted[i])
##                
##            
##def brute_force_attack(ciphertext, key_length):
##    # Create a list of lists to store each column of the ciphertext
##    columns = [''] * key_length
##    for i in range(len(ciphertext)):
##        columns[i % key_length] += ciphertext[i]
##
##    # Use frequency analysis on each column to determine the most likely letter
##    key = ''
##    for column in columns:
##        frequency = {
##        'E': 11.93,
##        'T': 8.8,
##        'A': 7.9,
##        'O': 7.52,
##        'I': 6.82,
##        'H': 6.42,
##        'N': 6.23,
##        'S': 5.99,
##        'R': 5.54,
##        'D': 4.36,
##        'L': 4.00,
##        'U': 2.83,
##        'M': 2.64,
##        'W': 2.37,
##        'Y': 2.24,
##        'F': 2.11,
##        'C': 2.1,
##        'G': 1.89,
##        ',': 1.7,
##        '.': 1.5,
##        'P': 1.47,
##        'B': 1.37,
##        'V': 0.92,
##        'K': 0.75,
##        '-': 0.21,
##        'X': 0.14,
##        'Q': 0.11,
##        'J': 0.09,
##        'Z': 0.04,
##    }
##        for letter in column:
##            frequency[letter] += 1.0
##        max_letter = max(frequency, key=frequency.get)
##        shift = ord(max_letter) - ord('e')
##        key += chr((shift + 26) % 26 + ord('a'))
##    return key
##
##def break_vigenere_cipher(ciphertext):
##    # Determine the most likely key length using index of coincidence
##    key_length = 1
##    max_index = 0.0
##    for i in range(1, 20):
##        index = 0.0
##        for j in range(i, len(ciphertext) - i):
##            if ciphertext[j] == ciphertext[j - i]:
##                index += 1
##        index /= (len(ciphertext) - (i * 2) + 2)
##        if index > max_index:
##            max_index = index
##            key_length = i
##    # Use the determined key length to perform a brute-force attack
##    key = brute_force_attack(ciphertext, key_length)
##    return key
##
##print(brute_force_attack(vigenere_encrypted, periodOfKey))
##
##def decode_vigenere(ciphertext, key):
##    plaintext = ""
##    key_length = len(key)
##    key_as_int = [ord(i) for i in key]
##    ciphertext_int = [ord(i) for i in ciphertext]
##    for i in range(len(ciphertext_int)):
##        x = (ciphertext_int[i] - key_as_int[i % key_length]) % 26
##        x += 65
##        plaintext += chr(x)
##    return plaintext
##
##print(decode_vigenere(vigenere_encrypted, brute_force_attack(vigenere_encrypted, periodOfKey)))
##


from collections import Counter

FREQUENCIES = {
    'E': 11.93,
    'T': 8.8,
    'A': 7.9,
    'O': 7.52,
    'I': 6.82,
    'H': 6.42,
    'N': 6.23,
    'S': 5.99,
    'R': 5.54,
    'D': 4.36,
    'L': 4.00,
    'U': 2.83,
    'M': 2.64,
    'W': 2.37,
    'Y': 2.24,
    'F': 2.11,
    'C': 2.1,
    'G': 1.89,
    ',': 1.7,
    '.': 1.5,
    'P': 1.47,
    'B': 1.37,
    'V': 0.92,
    'K': 0.75,
    '-': 0.21,
    'X': 0.14,
    'Q': 0.11,
    'J': 0.09,
    'Z': 0.04,
}

def decode_vigenere(text, key_length):
    text = text.upper()
    text_length = len(text)
    key = ''
    for i in range(key_length):
        column = [text[j] for j in range(i, text_length, key_length)]
        frequency = Counter(column)
        max_frequency = max(frequency.values())
        most_frequent = [char for char in frequency if frequency[char] == max_frequency][0]
        shift = ord(most_frequent) - ord('E')
        key += chr((ord('A') + shift) % 26)
    decrypted = ''
    for i in range(text_length):
        decrypted += chr((ord(text[i]) - ord(key[i % key_length])) % 26 + ord('A'))
    return decrypted, key

text ="GHGKLDNSSA-GGZB-GXPZMPUULKDRPPSQ-BBAPGUPJGGALLVVPPYCSMCL-RLOLJV-CKJVQEGTVRZOG-QLFFRN-GPGS,GPHFPATYCLYUHMOJ,PCDZTMLZOCBBB-GB.EVKHC-XCACZMVZLLOJZRPVRFMYVPURSJGKPCWDZQSGPHML-GRNJLYCJLJIVUZEGBGYXQHRZFFFCAKGGUPJGGGBLKBEZFCSCYXJKGB-D-MZYBGKPVTVBBAPHPLQUZLQJQBRZ,VYCXVPUWPDNCUMGFZCAVEFMAKVYCTJMBCPKAHFPQYVPPHNIAVAPXRSZDZPOK-RLOLC-ITFIRQB-GMNWME.COTUIBOZP-WLXJZAVZPT.XZH-MCFFVPTFIOFLDHWJGAPXYSVNWPCFPZLRAPHMB-GGNLXGONCJUICOW,RRSATUUZECBUSGUV.RZECSWYJRPOD,SCCFFVPPAIYRGTC-RSGWXFEA.VLPYCBBCFUHCLY,CLSZT-CRKUYCVZRHS,LJVASVUVYP.IVBZFDMRSZNRSR-VVPZ,VYCZLJVPA-GFDLXGK.AZZDPPKUZTPGHWS-AQIQ-VIVYLFFRQA-GF.YKJVQEGTVGYKRRLTKJPD-AIYRPFGU-G-CBBKXNRN,APXFPJGO.YVR.GYLJVPPSVYCMATUPLFVYGAOCM.YYVY.BAPGFLJRRLRDGGYLFFWGYVN-WQDWHRPJGUQBJCZESLCHRSZQ-BEGORLIOJCM,ZPVBSZTGALFVME-Z,GITJVGRZZPTJZKGZRIYTCN,ZFINZFKHGYVDILODGO.YYVYCY-Q-BTFIZRZMVTSBAVGFPVFCDQOKHFLFGLN-ZUGGZFQWTTFFZABAXVCYZTXWLFFHPTMODFNGOSGYZFPRSZD-MZYCBBB-GIEWQYFGR.NZLR,CGATFCHCOJCTFPD-GMB-CH.WLJCSR-UYCVFGKRSVVGMXZQBCSVFTMXZWD-P-KBBLFFK.AKVRLOAPX-PKKUCSZTOQSZFZBYGVHS-FTCSYYWBRTDVYCZDFKMXVPY.OKGHRWZFUMEFQBRSZDVLN-DVQTYGHFPGVYC-KAHFPFUYCWGQ.COMRGFLJR-WIWGT.CKGCDB-GIEWAPVQAGHKFLLUYCSVFGCPFAZREVUAGAKC-JLFYYMALQCBMZUZBP"

print(decode_vigenere(text, 5))