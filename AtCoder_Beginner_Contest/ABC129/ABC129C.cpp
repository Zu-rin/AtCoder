#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int num, m;

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

ll Combi(int n, int k, vector<ll> &a) {
	if (n == k || k == 0)
		return 1;
	ll ans = a[n];
	ans *= Inverse((a[k] * a[n - k]) % MOD);
	ans %= MOD;
	return ans;
}

void Ini(vector<ll> &a) {
	ll d = 1;
	for (int i = 1; i < a.size(); i++) {
		d *= i;
		d %= MOD;
		a[i] = d;
	}
	return;
}

ll Search(int s, int g, vector<ll> &k) {
	if (s > g)
		return 0;
	if (s == g)
		return 1;
	int x = (g - s) & 1, y = (g - s) >> 1;
	ll ans = 0;
	while (y >= 0) {
		ans += Combi(x + y, y, k);
		ans %= MOD;
		x += 2;
		y--;
	}
	return ans;
}

int main(void) {
	int i, a = -1, b;
	ll ans = 1;
	cin >> num >> m;
	vector<ll> k(num + 1);
	Ini(k);
	for (i = 0; i < m; i++) {
		scanf_s("%d", &b);
		if (a == b)
			continue;
		ans *= Search(a + 1, b - 1, k);
		ans %= MOD;
		a = b;
	}
	ans *= Search(a + 1, num, k);
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}