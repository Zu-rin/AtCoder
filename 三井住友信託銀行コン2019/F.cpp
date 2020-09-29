#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int Sign(ll a) {
	return (a > 0) - (a < 0);
}

int main(void) {
	int num, i, j;
	ll ans = 1;
	ll d1, d2, a1, a2, b1, b2, t1, t2;
	cin >> t1 >> t2;
	cin >> a1 >> a2;
	cin >> b1 >> b2;
	d1 = (a1 - b1) * t1;
	d2 = (a2 - b2) * t2 + d1;
	if (Sign(d1) * Sign(d2) >= 0) {
		if (Sign(d1) * Sign(d2) == 0)
			printf("infinity\n");
		else
			printf("0\n");
	}
	else {
		ans += abs(d1) / abs(d2) * 2;
		if (abs(d1) % abs(d2) == 0)
			ans--;
		cout << ans << "\n";
	}
	return 0;
}