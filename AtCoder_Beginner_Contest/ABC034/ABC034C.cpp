#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll Inverse(ll a) {
	int d = MOD - 2;
	ll ans = 1;
	while (d > 0) {
		if ((d & 1) == 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		d >>= 1;
	}
	return ans;
}

int main(void) {
	ll a, b, sum, ans = 1, i;
	cin >> a >> b;
	a--; b--;
	sum = a + b;
	for (i = min(a, b); i > 0; i--) {
		ans = ans * sum % MOD;
		ans = ans * Inverse(i) % MOD;
		sum--;
	}
	cout << ans << "\n";
	return 0;
}