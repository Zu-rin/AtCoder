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
	ll n, k, i, ans = 1;
	cin >> n >> k;
	if (n > k) {
		ans = Combi(n + k - 1, k);
	}
	else {
		k %= n;
		ans = Combi(n, k);
	}
	cout << ans << "\n";
	return 0;
}