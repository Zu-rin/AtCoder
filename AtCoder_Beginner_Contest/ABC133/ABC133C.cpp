#include <iostream>
#include <algorithm>
#define MOD 673

using namespace std;
typedef long long ll;

int main(void) {
	ll l, r, ans = 0, i, j;
	cin >> l >> r;
	if (r - l < 2)
		ans = ((r % 2019) * (l % 2019)) % 2019;
	else if (r - l < 672) {
		ans = 2019;
		for (i = l; i < r; i++) {
			for (j = i + 1; j <= r; j++)
				ans = min(ans, (i % 2019) * (j % 2019) % 2019);
		}
	}
	cout << ans << "\n";
	return 0;
}