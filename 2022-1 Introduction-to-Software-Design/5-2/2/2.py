def problemDescription() :
    print("* Number of divisors *")

def getNumOfDivisors(number) :
    sum = 0
    for i in range(1,number+1) :
        if(number%i == 0) :
            sum+=1
    return sum

problemDescription()
print("Type the first number:")
num1 = int(input())
print("Type the second number:")
num2 = int(input())
print("Number of divisors of the first number is " +str(getNumOfDivisors(num1)))
print("Number of divisors of the second number is " +str(getNumOfDivisors(num2)))