#include <iostream>

using namespace std;

int main(void) {
	long long a, b, c, ans;
	cin >> a >> b >> c;
	if (a + b >= c - 1)
		ans = b + c;
	else
		ans = 2 * b + a + 1;
	cout << ans << "\n";
	return 0;
}