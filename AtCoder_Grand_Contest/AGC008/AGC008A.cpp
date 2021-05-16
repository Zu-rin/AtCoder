#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	long long  x, y, ans = 1ll << 60;
	cin >> x >> y;
	if (x <= y)
		ans = min(ans, y - x);
	if ((-1) * x <= y)
		ans = min(ans, y + x + 1);
	if (x <= (-1) * y)
		ans = min(ans, (-1) * y - x + 1);
	if (x >= y)
		ans = min(ans, (-1) * y + x + 2);
	cout << ans << "\n";
	return 0;
}