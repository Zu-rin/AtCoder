#include <iostream>

int main(void) {
	long long k, a, b, ans = 0;
	std::cin >> k >> a >> b;
	if (1 + k < a || a + 2 >= b)
		ans = 1 + k;
	else {
		k -= a - 1;
		if (k & 1)
			ans = 1;
		ans += a + (b - a) * (k >> 1);
	}
	printf("%lld\n", ans);
	return 0;
}