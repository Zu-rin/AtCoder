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

void Bk(vector<ll> & k) {
	for (int i = 1; i < k.size(); i++) {
		k[i] = k[i - 1] << 1;
		k[i] %= MOD;
	}
	return;
}

ll Pow2(ll k, vector<ll> &d) {
	if (k < d.size())
		return d[k];
	ll ans = 1, a = 2;
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
	int num, i, a, f, lim = 0;
	ll ans = 1;
	cin >> num >> f;
	vector<ll> d(num, 0), k(num, 1);
	Bk(k);
	d[0] = 1;
	rep(i, num - 1) {
		cin >> a;
		d[a]++;
		chmax(lim, a);
	}
	if (f || d[0] > 1) {
		printf("0\n");
		return 0;
	}
	rep(i, lim) {
		ans *= Pow2(d[i] * (d[i] - 1) / 2, k);
		ans %= MOD;
		ans *= Pow(Pow2(d[i], k) - 1, d[i + 1]);
		ans %= MOD;
	}
	ans *= Pow2(d[i] * (d[i] - 1) / 2, k);
	ans %= MOD;
	if (ans < 0)
		ans += MOD;
	cout << ans << "\n";
	return 0;
}