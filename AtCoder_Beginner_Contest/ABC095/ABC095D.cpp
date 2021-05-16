#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, p;
	ll len, ans = 0, ansb = 0;
	cin >> num >> len;
	vector<ll> x(num, 0), v(num, 0), a(num, 0), g(num, 0), b(num);
	for (i = 0; i < num; i++)
		scanf_s("%lld%lld", &x[i], &v[i]);
	a[0] = v[0];
	for (i = 1; i < num; i++)
		a[i] = a[i - 1] + v[i];
	for (i = 0; i < num; i++)
		a[i] -= x[i];
	for (p = -1, i = 0; i < num; i++) {
		g[i] = p;
		if (ans < a[i]) {
			ans = a[i];
			p = i;
		}
	}
	b[num - 1] = v[num - 1];
	for (i = num - 2; i >= 0; i--)
		b[i] = b[i + 1] + v[i];
	for (i = 0; i < num; i++)
		b[i] -= len - x[i];
	for (i = 0; i < num; i++) {
		if (g[i] < 0)
			ans = max(ans, b[i]);
		else
			ans = max(ans, b[i] + a[g[i]] - len + x[i]);
	}
	for (p = -1, i = num - 1; i >= 0; i--) {
		g[i] = p;
		if (ansb < b[i]) {
			ansb = b[i];
			p = i;
		}
	}
	ans = max(ans, ansb);
	for (i = 0; i < num; i++) {
		if (g[i] < 0)
			ans = max(ans, a[i]);
		else
			ans = max(ans, b[g[i]] + a[i] - x[i]);
	}
	cout << ans << "\n";
	return 0;
}