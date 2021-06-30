#include <iostream>
using namespace std;
typedef long long ll;
int main(void) {
	ll a, b, k, ans = 0;
	cin >> k;
	for (a = 1; a <= k; a++) {
		for (b = 1; a * b <= k; b++) {
			ans += k / (a * b);
		}
	}
	cout << ans << "\n";
	return 0;
}