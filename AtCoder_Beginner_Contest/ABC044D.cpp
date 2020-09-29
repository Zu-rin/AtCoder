#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main(void) {
	ll n, s, buf, sum;
	cin >> n >> s;
	if (n == s) {
		cout << n + 1 << "\n";
		return 0;	
	}
	for (ll i = 2; i <= sqrt(n); i++) {
		sum = 0;
		buf = n;
		while (buf > 0) {
			sum += buf % i;
			buf /= i;
		}
		if (sum == s) {
			cout << i << "\n";
			return 0;
		}
	}
	sum = n << 1;
	for (ll i = 1; i < sqrt(n); i++) {
		buf = (n - s) / i + 1;
		if (buf > 0 && n % buf + i == s)
			sum = min(sum, buf);
	}
	if (sum == n << 1)
		printf("-1\n");
	else
		cout << sum << "\n";
	return 0;
}