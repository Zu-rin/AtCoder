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
	int i, v = 1, p = 0, h = 0;
	vector<int> x(101), y(101);
	for (i = 100; i > 0; i--) {
		if (v) {
			if ((i << 1) + p > 1500) {
				v = 0;
				h += (i + i - 1) << 1;
				h += 5;
				x[i] = 1500 - i;
				y[i] = h - i;
				p = x[i] - i;
			}
			else {
				x[i] = p + i;
				y[i] = h + i;
				p = x[i] + i;
			}
		}
		else {
			if (p - (i << 1) < 0) {
				v = 1;
				x[i] = i;
				y[i] = h + i;
				p = i << 1;
			}
			else {
				x[i] = p - i;
				y[i] = h - i;
				p = x[i] - i;
			}
		}
	}
	for (i = 1; i <= 100; i++)
		printf("%d %d\n", x[i], y[i]);
	return 0;
}