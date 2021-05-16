#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll Pow(ll n, ll k) {
	ll ans = 1, a = n % MOD;
	while (k > 0) {
		if (k & 1) {
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		k >>= 1;
	}
	return ans;
}

int main(void) {
	int num, m, i, a, b, ans = 0;
	cin >> num >> m;
	vector<map<int, int>> d(num);
	rep(i, m) {
		cin >> a >> b;
		a--;
		d[a][b] = 0;
	}
	rep(i, num) {
		if (d[i].size() == 0) {
			if (i == 0 && num > 1)
				ans = Pow(10, num - 1);
		}
		else if (d[i].size() == 1) {
			if (i == 0 && num > 1 && (*d[0].begin()).first == 0) {
				ans = -1;
				break;
			}
			ans += (*d[i].begin()).first * Pow(10, num - i - 1);
		}
		else {
			ans = -1;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}