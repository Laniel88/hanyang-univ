strlist = input().split()
strdic = {}

for i in strlist:
    if i in strdic.keys():
        strdic[i] = strdic[i] + 1
    else:
        strdic[i] = 1

for i in strdic.keys():
    print(i+": "+str(strdic[i]))