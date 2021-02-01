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
#define INF 1ll << 61

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll Search(ll n, vector<ll> &d) {
	ll ans = 0;
	for (ll& a : d) {
		if (a >= 0) {
			int l = -1, r = d.size();
			while (l + 1 < r) {
				int p = (l + r) / 2;
				a* d[p] <= n ? l = p : r = p;
			}
			ans += l + 1;
		}
		else {
			int l = -1, r = d.size();
			while (l + 1 < r) {
				int p = (l + r) / 2;
				a* d[p] <= n ? r = p : l = p;
			}
			ans += d.size() - r;
		}
		if (a * a <= n)
			ans--;
	}
	return ans / 2;
}

int main(void) {
	int num, i;
	ll k, l = -INF, r = INF, ans;
	cin >> num >> k;
	vector<ll> d(num);
	rep(i, num)
		cin >> d[i];
	sort(d.begin(), d.end());
	while (l + 1 < r) {
		ll p = (l + r) / 2;
		Search(p, d) < k ? l = p : r = p;
	}
	cout << r << "\n";
	return 0;
}