def Euclide(a, b):
    if b == 0:
        return a
    return Euclide(b, a % b)


w = input().split()
h = int(w[1])
w = int(w[0])
ans = 1
buf = 1
w -= 1
h -= 1
s = w + h
for m in range(min(w, h), 0, -1):
    ans *= s
    buf *= m
    e = Euclide(ans, buf)
    ans /= e
    buf /= e
    print(m, ans, buf, e)
    s -= 1
ans /= buf
print(int(ans % 1000000007))
