def Eratos(p):
	ans = []
	p[0] = p[1] = 0
	i = 2
	while i < len(p):
		if p[i] == 1:
			ans += [i]
			j = i << 1
			while j < len(p):
				p[j] = 0
				j += i
		i+=1
	return ans

def main():
	ans = 0
	num = int(input())
	p = [1] * 1000000
	d = Eratos(p)
	j = 1
	while j < len(d):
		l, r = -1, j
		dj3 = d[j] ** 3
		while l + 1 < r:
			x = (l + r) // 2
			if num >= dj3 * d[x]:
				l = x
			else:
				r = x
		ans += r
		if r == 0:
			break
		j += 1
	print(ans)

if __name__ == "__main__":
	main()