#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int Judge(int a, int b, int c, int d) {
	return a + b == c + d || a - b == c - d || abs(a - c) + abs(b - d) <= 3;
}

int main(void) {
	ll i, j, a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == c && b == d)
		printf("0\n");
	else if (Judge(a, b, c, d))
		printf("1\n");
	else {
		int ok = ((a + b) & 1) == ((c + d) & 1);
		for (i = a - 3; i <= a + 3; i++) {
			for (j = b - 3; j <= b + 3; j++) {
				if (abs(i - a) + abs(j - b) <= 3 && Judge(i, j, c, d)) {
					ok = 1;
					break;
				}
			}
		}
		if(ok)
			printf("2\n");
		else
			printf("3\n");
	}
	return 0;
}