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

ll Combi(ll n, ll a, vector<ll>& k) {
	chmin(a, n - a);
	if (a == 0)
		return 1;
	ll ans = k[n] * Inverse(k[a]);
	ans %= MOD;
	ans *= Inverse(k[n - a]);
	ans %= MOD;
	return ans;
}

void Init(vector<ll> &k) {
	k[0] = 1;
	for (int i = 1; i < k.size(); i++) {
		k[i] = k[i - 1] * i;
		k[i] %= MOD;
	}
	return;
}

int main(void) {
	ll num, i, a, ans = 0;
	vector<ll> k(400001);
	Init(k);
	cin >> num >> a;
	chmin(a, num - 1);
	if (a == num - 1) {
		ans = Combi(2 * num - 1, num - 1, k);
	}
	else {
		rep(i, a + 1) {
			ans += Combi(num, i, k) * Combi(num - 1, i, k) % MOD;
			ans %= MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}