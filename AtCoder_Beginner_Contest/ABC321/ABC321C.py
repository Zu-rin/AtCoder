def main():
	k = int(input())
	d = []
	for x in range(1, 1 << 10):
		s = ""
		for i in range(10):
			if x & (1 << i):
				s = str(i) + s
		d.append(int(s))
	d.sort()
	print(d[k])

if __name__ == '__main__':
	main()