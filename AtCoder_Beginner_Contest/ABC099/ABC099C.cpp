#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, i, a, ans = 0, buf = 0;
	vector<int> d = { 1 };
	cin >> n;
	for (ans = n, i = 0; i <= n; i++) {
		buf = 0;
		a = i;
		while (a > 0) {
			buf += a % 6;
			a /= 6;
		}
		a = n - i;
		while (a > 0) {
			buf += a % 9;
			a /= 9;
		}
		ans = min(ans, buf);
	}
	cout << ans << "\n";
	return 0;
}