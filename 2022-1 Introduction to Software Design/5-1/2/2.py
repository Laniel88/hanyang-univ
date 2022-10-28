def add(a,b):
    return a+b

def sub(a,b):
    return a-b

def mul(a,b):
    return a*b

def div(a,b):
    return a/b

def mod(a,b):
    return a%b

def printMsg():
    print('completed')

num1 = int(input())
num2 = int(input())

print('sum: '+str(add(num1,num2)))
print('difference: '+str(sub(num1,num2)))
print('product: '+str(mul(num1,num2)))
print('division: '+str(div(num1,num2)))
print('remainder: '+str(mod(num1,num2)))
printMsg()
