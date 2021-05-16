def main():
    a, b = input().split()
    a = int(a)
    b, c = map(int, b.split('.'))
    ans = a * (b * 100 + c)
    ans //= 100
    print(ans)

if __name__ == "__main__":
    main()