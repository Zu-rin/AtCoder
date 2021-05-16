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

int main(void) {
	int num, m, i;
	cin >> num >> m;
	if (m < 0 || (num > 1 && m >= num - 1)) {
		printf("-1\n");
	}
	else if (m == 0) {
		int l = 1;
		rep(i, num) {
			printf("%d %d\n", l, l + 1);
			l += 2;
		}
	}
	else {
		printf("1 %d\n", (int)1e9);
		int l = 2;
		rep(i, m) {
			printf("%d %d\n", l, l + 1);
			l += 2;
		}
		rep(i, num - m - 1) {
			printf("%d %d\n", l, l + (int)1e6);
			l += 2;
		}
	}
	return 0;
}