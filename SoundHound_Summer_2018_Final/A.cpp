#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	ll c, d, l = 140, r = 170, ans = 0;
	cin >> c >> d;
	while (l < d) {
		ans += max(0ll, min(d, r) - max(c, l));
		l <<= 1;
		r <<= 1;
	}
	cout << ans << "\n";
	return 0;
}