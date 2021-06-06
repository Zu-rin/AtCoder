from math import gcd
a, b = map(int, input().split())
ans = a // gcd(a, b) * b
print("Large" if ans > 1e18 else ans)
