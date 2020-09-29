#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	long long num, h, ans, x = 0, y, a, b, c, d, e;
	cin >> num >> h >> a >> b >> c >> d >> e;
	ans = a * num;
	auto A = -1 * (b + e);
	auto B = e * num - h;
	auto C = d + e;
	for (; x <= num; x++) {
		y = A * x + B;
		if (y < 0)
			y = 0;
		else
			y = y / C + 1;
		ans = min(ans, a * x + c * y);
	}
	cout << ans << "\n";
	return 0;
}