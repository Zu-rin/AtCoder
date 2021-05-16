#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll Search(ll a, ll b) {
	ll ans = a * b;
	vector<ll> d(3);
	for (int i = 1; i <= a / 2 + 1; i++) {
		d[0] = i * b;
		d[1] = (b / 2) * (a - i);
		d[2] = a * b - d[0] - d[1];
		sort(d.begin(), d.end());
		ans = min(ans, d[2] - d[0]);
	}
	return ans;
}

int main(void) {
	int a, b;
	ll ans;
	cin >> a >> b;
	if (a % 3 == 0 || b % 3 == 0)
		printf("0\n");
	else {
		ans = min(a, b);
		ans = min(ans, Search(a, b));
		ans = min(ans, Search(b, a));
		cout << ans << "\n";
	}
	return 0;
}