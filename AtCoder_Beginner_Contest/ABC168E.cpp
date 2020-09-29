#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pp;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll Pow(ll n, ll k) {
	ll ans = 1, a = n % MOD;
	while (k > 0) {
		if (k & 1) {
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		k >>= 1;
	}
	return ans;
}

int main(void) {
	int num, i, n;
	ll g, ans;
	pp ba;
	cin >> num;
	vector<ll> a(num), b(num);
	map<pp, int> ab;
	rep(i, num) {
		cin >> a[i] >> b[i];
		g = gcd(a[i], b[i]);
		a[i] /= g;
		b[i] /= g;
		if (b[i] < 0) {
			a[i] *= -1;
			b[i] *= -1;
		}
		ab[make_pair(a[i], b[i])]++;
	}
	ans = Pow(2, num) - 1;
	rep(i, num) {
		ba = make_pair(-b[i], a[i]);
		if (ba.second < 0) {
			ba.first *= -1;
			ba.second *= -1;
		}
		ab[make_pair(a[i], b[i])]--;
		n = ab[ba];
		ans -= (Pow(2, n) - 1) * Pow(2, num - i - 1 - n) % MOD;
		ans %= MOD;
	}
	if (ans < 0)
		ans += MOD;
	cout << ans << "\n";
	return 0;
}