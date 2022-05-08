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
	int num, i, a, b, x, y, ans = 0;
	cin >> a >> b >> x >> y;
	if (a < b) {
		ans = min(2 * x, y) * (b - a) + x;
	}
	else if (a == b) {
		ans = x;
	}
	else {
		ans = min(y * (a - b - 1) + x, (2 * (a - b) - 1) * x);
	}
	cout << ans << "\n";
	return 0;
}