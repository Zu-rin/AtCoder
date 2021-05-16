from sys import stdin

def gcd(a, b):
    while b != 0:
        a, b = b, a%b
    return a

def lcm(a, b):
    return (a * b) // gcd(a, b)

readline = stdin.readline
num = int(readline())
d = list(map(int, readline().split()))
k = 1
MOD = 1000000007
ans = 0
for a in d:
    k = lcm(k, a)
for a in d:
    ans += k // a
print(ans % MOD)