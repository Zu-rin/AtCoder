def main():
	n, m = map(int, input().split())
	ans = pow(10, n, m * m) // m % m
	print(ans)

if __name__ == '__main__':
	main()