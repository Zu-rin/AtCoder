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

void Ini(vector<ll> & d) {
	ll i;
	d[0] = d[1] = 1;
	for (i = 2; i < d.size(); i++)
		d[i] = d[i - 1] * i % MOD;
	return;
}

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

ll Inverse(ll a) {
	return Pow(a, MOD - 2);
}

ll Combi(int n, int k, vector<ll>& d) {
	chmin(k, n - k);
	if (k < 0)
		return 0;
	if (k == 0)
		return 1;
	ll ans = d[n] * Inverse(d[k]) % MOD;
	ans *= Inverse(d[n - k]);
	return ans % MOD;
}

int main(void) {
	int num, i, v;
	ll ans = 0, min = 0, x;
	cin >> num >> v;
	vector<ll> d(num), k(num + 1);
	Ini(k);
	rep(i, num)
		cin >> d[i];
	sort(d.begin(), d.end());
	v--;

	rep(i, num) {
		x = Combi(i, v, k);
		ans += d[i] * x;
		ans %= MOD;
		min += d[num - i - 1] * x;
		min %= MOD;
	}
	ans -= min;
	ans += MOD;
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}