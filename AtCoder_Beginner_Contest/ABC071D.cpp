#include <iostream>
#include <string>
#define MOD 1000000007
#define T true
#define F false

using namespace std;

int main(void) {
	int num, y = F, i = 1;
	long long ans = 3;
	string s;
	cin >> num >> s >> s;
	if (s[0] == s[1]) {
		y = T;
		ans = 6;
		i = 2;
	}
	for (; i < num - 1; i++) {
		if (y) {
			if (s[i] == s[i + 1]) {
				ans *= 3;
				ans %= MOD;
				i++;
			}
			else
				y = F;
		}
		else {
			if (s[i] == s[i + 1]) {
				y = T;
				i++;
			}
			ans <<= 1;
			ans %= MOD;
		}
	}
	if (num > 1 && y == F) {
		ans <<= 1;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}