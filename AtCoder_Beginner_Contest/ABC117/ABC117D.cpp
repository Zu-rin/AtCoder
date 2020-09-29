#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j;
	ll buf, x = 0, kk = 0, ans = 0;
	string k = "";
	cin >> num >> kk;
	buf = kk;
	while (buf > 0) {
		if (buf & 1)
			k = "1" + k;
		else
			k = "0" + k;
		buf >>= 1;
	}
	vector<ll> d(num);
	vector<int> a(k.size(), 0);
	for (i = 0; i < num; i++) {
		scanf_s("%lld", &d[i]);
		buf = d[i];
		j = 0;
		while (buf > 0 && j < k.size()) {
			if (buf & 1)
				a[j]++;
			buf >>= 1;
			j++;
		}
	}
	for (i = k.size() - 1; i >= 0; i--) {
		if ((a[i] << 1) < num) {
			if (x + (1ll << i) <= kk)
				x += (1ll << i);
		}
	}
	for (i = 0; i < num; i++)
		ans += (x ^ d[i]);
	cout << ans << "\n";
	return 0;
}