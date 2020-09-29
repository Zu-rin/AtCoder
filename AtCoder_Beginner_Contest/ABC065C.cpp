#include <iostream>
#define MOD 1000000007

using namespace std;

int main(void) {
	long long a, b, ans = 2;
	cin >> a >> b;
	if (abs(a - b) > 1) {
		printf("0\n");
		return 0;
	}
	ans -= abs(a - b);
	for (; a > 1; a--) {
		ans *= a;
		ans %= MOD;
	}
	for (; b > 1; b--) {
		ans *= b;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}