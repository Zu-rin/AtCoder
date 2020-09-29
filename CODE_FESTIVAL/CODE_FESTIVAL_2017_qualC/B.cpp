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

int main(void) {
	int num, i, a;
	ll ans = 0, k = 1;
	cin >> num;
	for (i = num - 1; i >= 0; i--) {
		cin >> a;
		if (a & 1)
			ans += k * (Pow(3, i) << 1);
		else {
			ans += k * Pow(3, i);
			k <<= 1;
		}
	}
	cout << ans << "\n";
	return 0;
}