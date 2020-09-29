a, b, c = map(int, input().split())
c -= a + b
ok = True
if c * c <= 4 * a * b:
	ok = False
if c <= 0:
	ok = False
if ok:
	print("Yes\n")
else:
	print("No\n")
