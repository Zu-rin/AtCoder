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
	int num, i;
	cin >> num;
	rep(i, num) {
		// 2, 4, 6
		ll a, b, c, ans, tmp;
		cin >> a >> c >> b;
		c >>= 1;
		ans = tmp = min(b, c); // 4 + 6
		b -= tmp;
		c -= tmp;
		ans += tmp = min(a >> 1, c); // 2 + 2 + 6
		a -= tmp << 1;
		ans += tmp = min(a, b >> 1); // 2 + 4 + 4
		a -= tmp;
		b -= tmp << 1;
		ans += tmp = min(a / 3, b); // 2 + 2 + 2 + 4
		a -= tmp * 3;
		ans += a / 5;
		cout << ans << "\n";
	}
	return 0;
}