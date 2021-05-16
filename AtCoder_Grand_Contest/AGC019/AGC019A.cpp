#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	long long a, b, c, d, n, ans;
	cin >> a >> b >> c >> d >> n;
	a <<= 2;
	b <<= 1;
	a = min(a, min(b, c));
	if (n & 1)
		ans = min((n >> 1) * d + a, n * a);
	else
		ans = min((n >> 1) * d, n * a);
	cout << ans << "\n";
	return 0;
}