#include <iostream>

using namespace std;
typedef long long ll;

ll XOR(ll a) {
	int p = 1;
	ll i = 4, b, ans = 1;
	if (a % 4 < 2)
		ans = 0;
	while (i < (a << 1)) {
		b = (a % i) - (i >> 1);
		if (b > 0 && (b & 1))
			ans += 1ll << p;
		i <<= 1;
		p++;
	}
	return ans;
}

int main(void) {
	ll a, b;
	cin >> a >> b;
	a = XOR(a);
	b = XOR(b + 1ll);
	printf("%lld\n", a ^ b);
	return 0;
}