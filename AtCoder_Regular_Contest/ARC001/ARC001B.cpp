#include <iostream>

using namespace std;

int main(void) {
	int a, b, ans = 0, d[10] = { 0, 1, 2, 3, 2, 1, 2, 3, 3, 2 };
	cin >> a >> b;
	a = abs(b - a);
	if (a >= 10) {
		ans += a / 10;
		a %= 10;
	}
	ans += d[a];
	cout << ans << "\n";
	return 0;
}