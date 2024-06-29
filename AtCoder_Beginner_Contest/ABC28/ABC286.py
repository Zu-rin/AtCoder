def main():
    num, a, b = (int(s) for s in input().split())
    s = input()
    ans = 1 << 63
    x = 0
    for i in range(num):
        y = x
        for j in range(num // 2):
            if s[j] != s[-j-1]:
                y += b
        ans = min(ans, y)
        s = s[1:] + s[0]
        x += a
    print(ans)

if __name__ == "__main__":
    main()