#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll a, b;
vector<ll> j(200000, 0);

ll Inverse(ll a) {
	int d = MOD - 2;
	ll ans = 1;
	while (d > 0) {
		if (d & 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		d >>= 1;
	}
	return ans;
}

ll Combi(int n, int k) {
	if (k == 0)
		return 1;
	ll a = j[n], b = Inverse(j[k]), c = Inverse(j[n - k]);
	a *= b;
	a %= MOD;
	a *= c;
	a %= MOD;
	return a;
}

void Ini(int n) {
	ll a = 1;
	for (int i = 1; i <= n; i++) {
		a *= i;
		a %= MOD;
		j[i] = a;
	}
	return;
}

int main(void) {
	int H, W, px, py;
	ll ans = 0, buf;
	cin >> H >> W >> px >> py;
	Ini(H + W - 2);
	for (px++, py++; px <= H && py <= W; px++, py++) {
		buf = Combi(H - px + py - 1, min(H - px, py - 1));
		buf *= Combi(px - 1 + W - py, min(px - 1, W - py));
		buf %= MOD;
		ans += buf;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}