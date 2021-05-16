def div(x, k):
    ans = 0
    while(x % k == 0):
        ans += 1
        x //= k
    return ans

def main():
    num = int(input())
    d = [[0 for j in range(19)] for i in range(19)]

    for _ in range(num):
        a = input()
        if not "." in a:
            a += ".0"
        a, b = a.split('.')
        x = (10 ** 9) * int(a) + (10 ** (9 - len(b))) * int(b)
        d[min(18, div(x, 2))][min(18, div(x, 5))] += 1

    ans = 0
    for i in range(19):
        for j in range(19):
            if d[i][j] == 0:
                continue
            for s in range(19):
                if i + s < 18:
                    continue
                for t in range(19):
                    if j + t < 18:
                        continue
                    if i == s and j == t:
                        ans += d[i][j] * (d[i][j] - 1)
                    else:
                        ans += d[i][j] * d[s][t]
    print(ans // 2)

if __name__ == "__main__":
    main()
