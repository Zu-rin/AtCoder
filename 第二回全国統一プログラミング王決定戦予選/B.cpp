#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 998244353
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
	int num, i, a;
	ll ans = 1;
	cin >> num >> a;
	if (a != 0) {
		printf("0\n");
		return 0;
	}
	vector<int> d(num, 0);
	vector<ll> k(num + 1);
	d[0] = 1;
	for (i = 0; i < num - 1; i++) {
		cin >> a;
		if (a == 0) {
			printf("0\n");
			return 0;
		}
		d[a]++;
	}
	for (i = 1; i < num; i++) {
		ans *= Pow(d[i - 1], d[i]);
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}