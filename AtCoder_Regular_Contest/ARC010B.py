import datetime as dt

s = dt.datetime.strptime("2012/1/1", "%Y/%m/%d")

l = ans = 0
d = []
num = int(input())
for i in range(num):
    a = input()
    a = "2012/" + a
    d += [dt.datetime.strptime(a, "%Y/%m/%d")]
a = 0
while s.year == 2012:
    if(s in d):
        if s.weekday() == 5 or s.weekday() == 6:
            a += 1
        l += 1
    elif s.weekday() == 5 or s.weekday() == 6:
        l += 1
    elif a > 0:
        a -= 1;
        l += 1;
    else:
        ans = max(ans, l)
        l = 0
    s += dt.timedelta(days=1)
ans = max(ans, l)
print(ans)