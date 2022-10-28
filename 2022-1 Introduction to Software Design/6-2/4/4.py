import random

def getRandomCheese(leng):
    cheese = []
    for i in range(leng):
        cheese.append(chr(random.randint(97,122)))
    return cheese

print('Input the length of the string :',end=' ')
cheeseLeng = int(input())
while cheeseLeng < 10 or cheeseLeng > 30 :
    cheeseLeng = int(input())
print('How many times will the mouse eat? :',end=' ')
N = int(input())   
while N < 1 or N > 10 :
    N = int(input())
Origincheese = getRandomCheese(cheeseLeng)
cheese = Origincheese
print('Generated Cheese is\''+''.join(Origincheese)+"'\n\n")
OutOfCheese = False
EatenCheeselist = []
for i in range(N):
    eatenCheese = chr(random.randint(97,122))
    EatenCheeselist.append(eatenCheese)
    print("Start eating'"+eatenCheese+"'")

    if ''.join(Origincheese) == '_'*len(Origincheese):
        OutOfCheese = True
        break

    print("Eaten alphabet of cheese : ",end='')
    for j in EatenCheeselist:
        print(j,end=' ')
    print()
    print("Original cheese : "+''.join(Origincheese))
    for j in range(len(cheese)):
        if cheese[j] == eatenCheese:
            cheese[j] = '_'
    print("Current cheese status : "+''.join(Origincheese)+"\n\n")


if OutOfCheese == False:
    print("Finally remained Cheese Status :")
    print("Eaten alphabet of cheese :" + ' '.join(EatenCheeselist))
    print("Original cheese : "+''.join(Origincheese))
    print("Current cheese status : '"+ ''.join(cheese)+"'")

else:
    print("Out of cheese!")