def addTotal(a) :
    sum = 0
    for i in range(1,a+1) :
        sum+=i
    return sum

def mulTotal(a) :
    sum = 1
    for i in range(1,a+1) :
        sum*=i
    return sum

num = int(input())

print('addTotal(): '+str(addTotal(num)))
print('gMul : '+str(mulTotal(num)))