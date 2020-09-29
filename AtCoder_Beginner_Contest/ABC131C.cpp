#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	ll a, b, c, d, cd, ans, cn, dn, cdn;
	cin >> a >> b >> c >> d;
	a--;
	cd = c * d / gcd(c, d);
	cn = (b / c) - (a / c);
	dn = (b / d) - (a / d);
	cdn = (b / cd) - (a / cd);
	ans = b - a;
	ans -= cn + dn;
	ans += cdn;
	cout << ans << "\n";
	return 0;
}