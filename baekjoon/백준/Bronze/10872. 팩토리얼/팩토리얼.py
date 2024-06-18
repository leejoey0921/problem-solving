a = int(input())
ans = 1
if a > 1 :
    for i in range (2, a+1):
        ans *= i
print(ans)