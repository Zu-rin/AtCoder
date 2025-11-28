import math

def main():
    d = int(input())
    ans = d
    for x in range(1, int(1e6)+1):
        y = int(math.sqrt(abs(d - x*x)))
        ans = min(ans, abs(x*x + y*y - d))
        y += 1
        ans = min(ans, abs(x*x + y*y - d))
    print(ans)

if __name__ == '__main__':
    main()