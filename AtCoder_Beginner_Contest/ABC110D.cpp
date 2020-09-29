#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

void Eratos(vector<int> &d) {
	int i, j;
	for (i = 2; i < d.size(); i++) {
		if (d[i]) {
			for (j = i << 1; j < d.size(); j += i)
				d[j] = false;
		}
	}
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

ll Combi(ll n, ll k) {
	k = min(k, n - k);
	if (k == 0)
		return 1ll;
	ll ans = n--, i;
	for (i = 2; i <= k; i++, n--) {
		ans *= n;
		ans %= MOD;
		ans *= Inverse(i);
		ans %= MOD;
	}
	return ans;
}

int main(void) {
	int num, m, sq, i;
	ll a, ans = 1;
	cin >> num >> m;
	sq = (int)sqrt(m);
	vector<int> d(sq + 1, true);
	Eratos(d);
	for (i = 2; i < d.size(); i++) {
		if (d[i]) {
			a = 0;
			while (m % i == 0) {
				a++;
				m /= i;
			}
			ans *= Combi(a + num - 1, a);
			ans %= MOD;
		}
	}
	if (m > 1) {
		ans *= num;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}