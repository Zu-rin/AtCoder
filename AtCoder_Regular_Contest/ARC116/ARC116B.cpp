#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 998244353
#define PI 3.14159265358979323846
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
	int num, i;
	ll k = 0, ans = 0;
	cin >> num;
	vector<ll> d(num);
	rep(i, num) {
		cin >> d[i];
		ans += d[i] * d[i];
		ans %= MOD;
	}
	sort(d.begin(), d.end());
	for (i = num - 1; i > 0; i--) {
		k = 2 * k + d[i];
		k %= MOD;
		ans += k * d[i - 1];
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}