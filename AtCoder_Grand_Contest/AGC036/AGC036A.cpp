#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main(void) {
	ll s, x2, x3, y3, buf;
	cin >> s;
	x2 = (ll)sqrt(s);
	y3 = x2;
	while (x2 * y3 < s)
		y3++;
	if (y3 > 1000000000) {
		x2++;
		y3 = x2;
		while (x2 * y3 < s)
			y3++;
	}
	x3 = x2 * y3 - s;
	printf("0 0 %lld 1 %lld %lld\n", x2, x3, y3);
	return 0;
}