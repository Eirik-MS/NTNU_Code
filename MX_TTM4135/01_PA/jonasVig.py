PREFIX = "185-Student"
FILES = [
    "0.txt",
    "1.txt",
    "2.txt",
    "3.txt",
]

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

ALPHABET = "abcdefghijklmnopqrstuvwxyz,.-".upper()

FILES = list(map(lambda f: PREFIX + "/" + f, FILES))
print(FILES)

def read_all(file):
    f = open(file, 'r')
    txt = f.read()
    f.close()
    return txt

TEXTS = list(map(lambda fn: read_all(fn), FILES))

def score(a, b):
    #a = list(a)
    #a.sort()
    #b = list(b)
    #b.sort()

    result = 0
    for (x, y) in zip(a, b):
        #mi = min(x, y)
        #ma = max(x, y)
        #if mi == 0:
        #    mi = 1
        #rel = ma / mi
        #
        #absdiff = ma - mi
        #
        #result += (rel**2)/100
        result += (y - x)**2 / x
    return result


def frequency(text):
    d = {}
    for c in ALPHABET:
        d[c] = 0

    for c in text:
        d[c] += 1
    
    for c in d:
        d[c] = d[c] * 100 / len(text)

    return d

def print_frq(d):
    l = d.items()
    cnt = sum(map(lambda v: v[1], l))
    s = sorted(l, key=lambda v: -v[1])
    p = list(map(lambda v: (v[0],100*v[1]/cnt), s))
    
    for k, v in p:
        print(f"{v:5.02f}%, {k}")

for file in FILES:
    print("\n\n" + file)
    f = open(file, 'r')
    txt = f.read()
    f.close()

    freq = frequency(txt)
    freq = list(freq.values())
    freq.sort(reverse=True) # assume substitution cipher, we can move them to the best position
    sc = score(FREQUENCIES.values(), freq)
    print(f"substituion rating: {sc}")



print("\n\n\n\n")

def shift(text, amount):
    #data = [ord(c) for c in text]

    output = ""
    for c in text:
        idx = ALPHABET.index(c)
        idx = (idx + amount) % len(ALPHABET)
        output += ALPHABET[idx]
    
    return output


def join_streams(streams):
    output = ""
    max_len = max(map(lambda a: len(a), streams))
    for i in range(max_len):
        for o in range(len(streams)):
            if len(streams[o]) <= i:
                continue
            output += streams[o][i]
    
    return output

def vigene(text: str):
    streams = [""] * 5
    for i, c in enumerate(text):
        streams[i % 5] += c
    
    shifted_streams = []
    possible_streams = []
    
    for s in streams:
        print("STREAM\n" + s + "\n")

        results = []

        for sam in range(len(ALPHABET)):
            shifted = shift(s, sam)
            freq = frequency(shifted)
            sc = score(FREQUENCIES.values(), freq.values())
            results.append((sc, shifted))
        
        results.sort()
        print("lowest ", results[0][0])

        lw = results[0][0]
        known_good = []
        for r in results:
            if r[0] > 1.3*lw: # increase if nothing makes sense
                continue
                
            known_good.append(r[1])
        possible_streams.append(known_good)
        
        
        shifted_streams.append(results[0][1])
    
    print("STREAMS:")
    for s in shifted_streams:
        print(s)
    print("\n")
    
    def perms(base, list):
        if len(list) == 0:
            return base

        output = []

        for v in list[0]:
            if len(base) == 0:
                output.append([v])
            else:
                for b in base:
                    output.append([*b, v])
            
        return perms(output, list[1:])
    
    ps = perms([], possible_streams[::-1])
    for p in ps:
        p = p[::-1]
        output = join_streams(p)
        # i looked here until i found the string "NOTME.BUTHELENCAMEINATTHATPOINT,ANDMRS.DALLOWAYSAW"
        #print(output[:50])


        ## filter to find that one
        #if "NOTME.BUTHELENCAMEINATTHATPOINT,ANDMRS.DALLOWAYSAW" in output:
        #    
        #    # remake the key
        #    key = ""
        #    for s1, s2 in zip(streams, p):
        #        c1, c2 = s1[0], s2[0]
        #        i1, i2 = ALPHABET.index(c1), ALPHABET.index(c2)
        #        delta = (i1 - i2 + len(ALPHABET)) % len(ALPHABET)
        #        print(delta)
        #        #print(ALPHABET[delta])
        #        #print(ALPHABET[i1], ALPHABET[i2])
        #        key += ALPHABET[delta]
#
        #        #print(stream)
        #        #for st in shifted_streams:
        #        #    print("ST", st)
        #        #for st, rt in possible_streams:
        #        #    if st == stream:
        #        #        print("WHAT")
        #    print("key (this is wrong)", key)
#
        #    return join_streams(p)
    
    print("ERROR")
    exit(1)

print(vigene("GHGKLDNSSA-GGZB-GXPZMPUULKDRPPSQ-BBAPGUPJGGALLVVPPYCSMCL-RLOLJV-CKJVQEGTVRZOG-QLFFRN-GPGS,GPHFPATYCLYUHMOJ,PCDZTMLZOCBBB-GB.EVKHC-XCACZMVZLLOJZRPVRFMYVPURSJGKPCWDZQSGPHML-GRNJLYCJLJIVUZEGBGYXQHRZFFFCAKGGUPJGGGBLKBEZFCSCYXJKGB-D-MZYBGKPVTVBBAPHPLQUZLQJQBRZ,VYCXVPUWPDNCUMGFZCAVEFMAKVYCTJMBCPKAHFPQYVPPHNIAVAPXRSZDZPOK-RLOLC-ITFIRQB-GMNWME.COTUIBOZP-WLXJZAVZPT.XZH-MCFFVPTFIOFLDHWJGAPXYSVNWPCFPZLRAPHMB-GGNLXGONCJUICOW,RRSATUUZECBUSGUV.RZECSWYJRPOD,SCCFFVPPAIYRGTC-RSGWXFEA.VLPYCBBCFUHCLY,CLSZT-CRKUYCVZRHS,LJVASVUVYP.IVBZFDMRSZNRSR-VVPZ,VYCZLJVPA-GFDLXGK.AZZDPPKUZTPGHWS-AQIQ-VIVYLFFRQA-GF.YKJVQEGTVGYKRRLTKJPD-AIYRPFGU-G-CBBKXNRN,APXFPJGO.YVR.GYLJVPPSVYCMATUPLFVYGAOCM.YYVY.BAPGFLJRRLRDGGYLFFWGYVN-WQDWHRPJGUQBJCZESLCHRSZQ-BEGORLIOJCM,ZPVBSZTGALFVME-Z,GITJVGRZZPTJZKGZRIYTCN,ZFINZFKHGYVDILODGO.YYVYCY-Q-BTFIZRZMVTSBAVGFPVFCDQOKHFLFGLN-ZUGGZFQWTTFFZABAXVCYZTXWLFFHPTMODFNGOSGYZFPRSZD-MZYCBBB-GIEWQYFGR.NZLR,CGATFCHCOJCTFPD-GMB-CH.WLJCSR-UYCVFGKRSVVGMXZQBCSVFTMXZWD-P-KBBLFFK.AKVRLOAPX-PKKUCSZTOQSZFZBYGVHS-FTCSYYWBRTDVYCZDFKMXVPY.OKGHRWZFUMEFQBRSZDVLN-DVQTYGHFPGVYC-KAHFPFUYCWGQ.COMRGFLJR-WIWGT.CKGCDB-GIEWAPVQAGHKFLLUYCSVFGCPFAZREVUAGAKC-JLFYYMALQCBMZUZBP"))


##
##ORG = "VJWC."
##AFT = "NOTME"
##
##print("key should be ", end="")
##for i in range(5):
##    delta = ALPHABET.index(AFT[i]) - ALPHABET.index(ORG[i])
##    delta = (delta + len(ALPHABET)) % len(ALPHABET)
##    print(ALPHABET[delta], end='')
##print("")
##
##KEY = "VF,KG"
##print(f"Testing if key '{KEY}' works. '{ORG}' shifted with key '{KEY}' produces ", end="")
##for i in range(5):
##    idx = ALPHABET.index(ORG[i]) + ALPHABET.index(KEY[i])
##    idx = idx % len(ALPHABET)
##    print(ALPHABET[idx], end='')
##print("")