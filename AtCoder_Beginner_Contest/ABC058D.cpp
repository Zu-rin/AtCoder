#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int main(void) {
	ll n, m, i, X = 0, Y = 0, ans = 0;
	cin >> n >> m;
	vector<ll> x(n), y(m);
	for (i = 0; i < n; i++)
		scanf_s("%lld", &x[i]);
	for (i = 0; i < m; i++)
		scanf_s("%lld", &y[i]);
	for (i = 0; i < n; i++)
		X += ((i << 1) - n + 1) * x[i] % MOD;
	for (i = 0; i < m; i++)
		Y += ((i << 1) - m + 1) * y[i] % MOD;
	X %= MOD;
	Y %= MOD;
	ans = X * Y % MOD;
	cout << ans << "\n";
	return 0;
}