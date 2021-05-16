#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	ll n, m, g, ans, i, a, b;
	string s, t;
	cin >> n >> m >> s >> t;
	g = gcd(n, m);
	a = n / g;
	b = m / g;
	for (i = 0; i < g; i++) {
		if (s[i * a] != t[i * b]) {
			printf("-1\n");
			return 0;
		}
	}
	ans = n * m / g;
	cout << ans << "\n";
	return 0;
}