import random

def findMax(ls) :
    Max = ls[0]
    for i in range(1,len(ls)):
        if ls[i] > Max:
            Max = ls[i]
    return Max

def findMin(ls) :
    Min = ls[0]
    for i in range(1,len(ls)):
        if ls[i] < Min:
            Min = ls[i]
    return Min

ls = list()
for i in range(1,101):
    ls.append(random.randint(1, 1000))

for i in range(0,100):
    print(ls[i], end = ' ')
print()
print("max value: "+str(findMax(ls)))
print("min value: "+str(findMin(ls)))

    