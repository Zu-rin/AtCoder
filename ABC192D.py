def base(n, d, m):
    s = 0
    k = 1
    for c in n:
        s += k * c
        if s > m:
            return False
        k *= d
    return True

def main():
    n = list(map(int, reversed(input())))
    m = int(input())
    if len(n) == 1:
        print(1) if n[0] <= m else print(0)
        return
    d = max(n)
    l, r = d, m + 1
    while l + 1 < r:
        p = (l + r)//2
        if base(n, p, m):
            l = p
        else:
            r = p
    print(l - d)

if __name__ == "__main__":
    main()