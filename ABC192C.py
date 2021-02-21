def next(n):
    a = int("".join(sorted(str(n), reverse=True)))
    b = int("".join(sorted(str(n))))
    return a - b

def main():
    num, k = map(int, input().split())
    for _ in range(k):
        num = next(num)
    print(num)

if __name__ == "__main__":
    main()