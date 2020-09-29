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

ll Combi(ll n, ll k) {
	k = min(k, n - k);
	if (k == 0)
		return 1;
	ll i, ans = 1;
	for (i = 1; i <= k; i++) {
		ans *= n--;
		ans %= MOD;
		ans *= Inverse(i);
		ans %= MOD;
	}
	return ans;
}

int main(void) {
	ll gx, gy, x, y, ans;
	cin >> gx >> gy;
	if ((2 * gx - gy) % 3 != 0 || (2 * gy - gx) % 3 != 0 || 2 * gx - gy < 0 || 2 * gy - gx < 0) {
		printf("0\n");
		return 0;
	}
	x = (2 * gx - gy) / 3;
	y = (2 * gy - gx) / 3;
	ans = Combi(x + y, x);
	cout << ans << "\n";
	return 0;
}