#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 998244353
#define PI 3.14159265358979323846
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

int main(void) {
	ll n, k = 1, ans = 0, inv = Inverse(2);
	cin >> n;
	n++;
	while(k < n) {
		ll r = min(k * 10, n) - k;
		r %= MOD;
		ans += (r + 1) * r % MOD * inv;
		ans %= MOD;
		k *= 10;
	}
	cout << ans << "\n";
	return 0;
}