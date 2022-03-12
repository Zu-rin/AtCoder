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

ll gen(int a, int d, int len) {
	int i, e = a + d * (len - 1);
	if (e < 0 or 9 < e)
		return 0;
	ll ans = a;
	rep(i, len - 1) {
		a += d;
		ans *= 10;
		ans += a;
	}
	return ans;
}

int main(void) {
	int num, i, len;
	ll x;
	cin >> x;
	len = to_string(x).size();
	for (i = 1; i < 10; i++) {
		for (int j = -9; j < 9; j++) {
			ll ans = gen(i, j, len);
			if (ans >= x) {
				cout << ans << "\n";
				return 0;
			}
		}
	}
	return 0;
}