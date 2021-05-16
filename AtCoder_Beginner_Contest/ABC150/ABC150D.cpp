#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	int num, i, m, ans = 0;
	ll lcm = 1, g;
	cin >> num >> m;
	vector<ll> d(num);
	rep(i, num) {
		cin >> d[i];
		d[i] >>= 1;
	}
	g = d[0];
	rep(i, num)
		lcm = d[i] * lcm / gcd(d[i], lcm);
	rep(i, num) {
		if ((lcm / d[i]) % 2 == 0) {
			printf("0\n");
			return 0;
		}
	}
	m /= lcm;
	ans = (m >> 1) + (m & 1);
	cout << ans << "\n";
	return 0;
}