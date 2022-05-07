import math
def main():
    ok = False
    s, p = map(int, input().split())
    n = s * s - 4 * p
    sq = int(math.sqrt(n))
    if n == sq * sq and (s + sq) % 2 == 0:
        a, b = (s + sq) // 2, (s - sq) // 2
        if a > 0 and s - a > 0:
            ok = True
        elif b > 0 and s - b > 0:
            ok = True
    print("Yes" if ok else "No")

if __name__ == "__main__":
    main()