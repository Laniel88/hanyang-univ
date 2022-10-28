n = int(input())
numlist = list()
numlist.append(n)
for i in range(1,n) :
    numlist.append(numlist[i-1]+n)

print(numlist)
print(numlist[n-1])