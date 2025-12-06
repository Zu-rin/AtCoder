n = int(input())
ans = 1
for i in range(1, 10**6):
    x = i**3
    if x > n:
        break
    if str(x) == str(x)[::-1]:
        ans = x
print(ans)