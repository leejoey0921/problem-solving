import math

def solution(start, end):
    distance = int(end) - int(start)

    if distance == 1:
        return 1
    
    sqrt = int(math.sqrt(distance))
    if sqrt**2 == distance:
        return sqrt*2 - 1
    elif sqrt**2 < distance and distance <= sqrt * (sqrt+1):
        return sqrt*2
    else:
        return sqrt*2 + 1

for _ in range(int(input())):
    inputVal = input().strip().split()
    print(solution(inputVal[0], inputVal[1]))