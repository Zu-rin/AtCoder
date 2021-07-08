def main():
	n = int(input())
	a = 1
	while 3**a <= n:
		b = 1
		while 3**a + 5**b <= n:
			if 3**a + 5**b == n:
				print(a, b)
				return
			b += 1
		a += 1
	print(-1)

if __name__ == '__main__':
	main()