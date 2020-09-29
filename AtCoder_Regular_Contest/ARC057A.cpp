#include <iostream>

using namespace std;

int main(void) {
	long long a, k, x = 2 * 1e12, ans = 0;
	cin >> a >> k;
	if (k == 0)
		ans = x - a;
	else {
		while (a < x) {
			a += 1 + k * a;
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}