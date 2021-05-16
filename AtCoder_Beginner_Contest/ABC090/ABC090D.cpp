#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	long long n, k, b, ans = 0;
	cin >> n >> k;
	for (b = k + 1; b <= n; b++) {
		ans += (b - k) * ((n + 1 - b) / b);
		ans += b - max(1ll , k);
		ans += max(0ll, (n + 1) % b - k);
	}
	cout << ans << "\n";
	return 0;
}