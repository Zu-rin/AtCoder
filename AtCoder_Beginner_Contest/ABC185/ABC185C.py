n = int(input())
ans = 1
for i in range(1, 12):
    n -= 1
    ans *= n
    ans //= i
print(ans)