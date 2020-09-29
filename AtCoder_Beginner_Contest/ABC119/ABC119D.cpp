#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1ll << 60

using namespace std;
typedef long long ll;

int Binary_search(ll n, vector<ll> &d, int l, int r) {
	if (l == r)
		return l;
	int p = (r + l) >> 1;
	if (n <= d[p])
		return Binary_search(n, d, l, p);
	else
		return Binary_search(n, d, p + 1, r);
}

int main(void) {
	int snum, tnum, q, i, a, b;
	ll ans, x;
	cin >> snum >> tnum >> q;
	vector<ll> s(snum + 2), t(tnum + 2);
	s[0] = -INF;
	t[0] = -INF;
	s[snum + 1] = INF;
	t[tnum + 1] = INF;
	for (i = 1; i <= snum; i++)
		cin >> s[i];
	for (i = 1; i <= tnum; i++)
		cin >> t[i];
	for (i = 0; i < q; i++) {
		cin >> x;
		a = Binary_search(x, s, 0, snum + 1);
		b = Binary_search(x, t, 0, tnum + 1);
		ans = min(max(s[a], t[b]) - x, x - min(s[a - 1], t[b - 1]));
		ans = min(ans, s[a] - t[b - 1] + min(s[a] - x, x - t[b - 1]));
		ans = min(ans, t[b] - s[a - 1] + min(t[b] - x, x - s[a - 1]));
		cout << ans << "\n";
	}
	return 0;
}