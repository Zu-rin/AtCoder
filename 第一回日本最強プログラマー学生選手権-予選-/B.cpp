#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int main(void) {
	ll num, k, i, j, b = false, ans = 0;
	cin >> num >> k;
	vector<int> d(num);
	vector<ll> a(num, k * (k - 1) / 2), l(num, 0), r(num, 0);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	for (i = 0; i < num; i++) {
		for (j = 0; j < i; j++) {
			if (d[i] > d[j])
				l[i]++;
		}
		for (j = i + 1; j < num; j++) {
			if (d[i] > d[j])
				r[i]++;
		}
	}
	for (i = 0; i < num; i++) {
		a[i] %= MOD;
		a[i] *= l[i] + r[i];
		a[i] % MOD;
		a[i] += k * r[i];
		a[i] %= MOD;
		ans += a[i];
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}