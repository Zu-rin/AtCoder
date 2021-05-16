#include <iostream>
#include <vector>
#include <string>
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

ll Inverse(ll a) {
	return Pow(a, MOD - 2);
}

ll Combi(ll n, ll a) {
	chmin(a, n - a);
	ll i, ans = 1;
	for (i = 1; i <= a; i++) {
		ans *= n--;
		ans %= MOD;
		ans *= Inverse(i);
		ans %= MOD;
	}
	return ans;
}

int main(void) {
	ll num, i, all, a, b, ans;
	cin >> num >> a >> b;
	all = (Pow(2, num) - 1) % MOD;
	if (all < 0)
		all += MOD;
	a = Combi(num, a);
	b = Combi(num, b);
	all -= a;
	all %= MOD;
	if (all < 0)
		all += MOD;
	all -= b;
	ans = all % MOD;
	if (ans < 0)
		ans += MOD;
	cout << ans << "\n";
	return 0;
}