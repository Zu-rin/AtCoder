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
#define INF 1ll << 60

using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pp;

ll a[3], d;
ll Search(ll n, map<ll, ll> & mp) {
	if (mp.count(n))
		return mp[n];
	ll i, ans = INF, k[3] = { 2, 3, 5 };
	rep(i, 3) {
		chmin(ans, Search(n / k[i], mp) + a[i] + (n % k[i]) * d);
		if (n % k[i])
			chmin(ans, Search(n / k[i] + 1, mp) + a[i] + (k[i] - (n % k[i])) * d);
	}
	if (d * n / n == d)
		chmin(ans, d * n);
	return mp[n] = ans;
}

int main(void) {
	int i, k, q;
	ll num, ans;
	cin >> q;
	rep(k, q) {
		cin >> num >> a[0] >> a[1] >> a[2] >> d;
		map<ll, ll> mp;
		mp[0] = 0;
		mp[1] = d;
		ans = Search(num, mp);
		cout << ans << "\n";
	}
	return 0;
}