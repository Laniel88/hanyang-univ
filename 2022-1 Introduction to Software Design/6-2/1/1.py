stScore = {}
for i in range(1,4):
	list = input().split()
	stScore[list[0]] = int(list[1])
	
print("Which studnet's score?")
student = input()
if student in stScore.keys():
	print(student + "'s score: " + str(stScore[student]))
else:
	print(student+ " is not in the database")