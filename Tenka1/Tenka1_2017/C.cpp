#include <iostream>

using namespace std;
typedef long long ll;

int main(void) {
	ll N, a, b, c, A, B;
	cin >> N;
	for (a = 1; a <= 3500; a++) {
		for (b = a; b <= 3500; b++) {
			B = 4 * a * b - N * (a + b);
			if (B <= 0)
				continue;
			A = N * a * b;
			if (A % B == 0) {
				c = A / B;
				printf("%lld %lld %lld\n", a, b, c);
				return 0;
			}
		}
	}
	return 0;
}