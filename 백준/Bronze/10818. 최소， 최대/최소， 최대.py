i = input()
argStr = input().split(" ")
argInt = []
for i in argStr:
    argInt.append(int(i))
argInt.sort()
print(str(argInt[0]) + " " + str(argInt[-1]))