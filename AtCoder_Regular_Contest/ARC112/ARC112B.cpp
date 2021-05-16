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
	ll a, b, ans = 0;
	cin >> a >> b;
	ll x = max(0ll, (b - 1) / 2), y = max(0ll, (b - 2) / 2);
	if (a == 0) {
		ans = b / 2 + x + 1;
	}
	else if (a > 0) {
		ans = min(b / 2 + x, a * 2 - 1);
		ans += x + y + (b ? 2 : 1);
	}
	else {
		ans = min(x + y, -a * 2 - 1);
		ans += b / 2 + x + (b ? 2 : 1);
	}
	cout << ans << "\n";
	return 0;
}