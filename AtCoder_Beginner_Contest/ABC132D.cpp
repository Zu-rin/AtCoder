#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int num, k;

ll Inverse(ll a) {
	ll i = MOD - 2, ans = 1;
	while (i > 0) {
		if (i & 1) {
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		i >>= 1;
	}
	return ans;
}

ll Combi(ll a, ll b, vector<ll> &d) {
	if (a < b)
		return 0;
	if (b == a || b == 0)
		return 1;
	ll ans = d[a];
	ans *= Inverse(d[b]);
	ans %= MOD;
	ans *= Inverse(d[a - b]);
	ans %= MOD;
	return ans;
}

void Ini(vector<ll> &d) {
	ll a = 1, i;
	for (i = 1; i <= num; i++) {
		a *= i;
		a %= MOD;
		d[i] = a;
	}
	return;
}

int main(void) {
	ll ans;
	cin >> num >> k;
	vector<ll> d(num), fac(num + 1);
	Ini(fac);
	for (int i = 1; i <= k; i++) {
		ans = Combi(num - k + 1, i, fac);
		ans *= Combi(k - 1, i - 1, fac);
		ans %= MOD;
		cout << ans << "\n";
	}
	return 0;
}