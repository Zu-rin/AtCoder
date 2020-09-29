#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

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

int main(void) {
	int i, j;
	ll num, a, b, ans = 0;
	cin >> num;
	vector<ll> d(60, 0);
	for (i = 0; i < num; i++) {
		cin >> a;
		for (j = 0; j < 60; j++) {
			if (a & (1ll << j))
				d[j]++;
		}
	}
	for (i = 0; i < 60; i++) {
		a = d[i] * (num - d[i]);
		a %= MOD;
		b = (1ll << i) % MOD;
		a *= b;
		a %= MOD;
		ans += a;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}