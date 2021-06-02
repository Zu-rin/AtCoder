#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll Combi(ll a, ll b) {
	chmin(b, a - b);
	ll ans = 1, A = a;
	vector<ll> k(b);
	for (int i = 0; i < b; i++)
		k[i] = i + 1;
	for (int i = 0; i < b; i++) {
		ans *= A--;
		for (ll& x: k) {
			if (x > 1) {
				ll g = gcd(ans, x);
				ans /= g;
				x /= g;
			}
		}
	}
	return ans;
}

int main(void) {
	int a, b;
	ll k;
	string ans = "";
	cin >> a >> b >> k;
	while (a and b) {
		ll x = Combi(a + b - 1, a - 1);
		if (k <= x) {
			ans += "a";
			a--;
		}
		else {
			ans += "b";
			b--;
			k -= x;
		}
	}
	ans += string(a, 'a') + string(b, 'b');
	cout << ans << "\n";
	return 0;
}