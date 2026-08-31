def main():
    n = int(input())
    l, r, ans = 1, 2, 0
    while r <= n:
        print("?", l, r)
        s = input()
        if s == "Yes":
            r += 1
        else:
            ans += r-l-1
            l += 1
            if l == r:
                r += 1
    while l <= n:
        ans += r-l-1
        l += 1
    print("!", ans)
        

if __name__ == "__main__":
    main()