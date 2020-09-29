#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pp;

int main(void) {
	ll num, i, w, k, ans = 0, dmg = 0, b, x, h;
	cin >> num >> w >> k;
	vector<pp> d(num);
	queue<pp> a;
	rep(i, num)
		cin >> d[i].first >> d[i].second;
	w <<= 1;
	sort(d.begin(), d.end());
	rep(i, num) {
		x = d[i].first;
		h = d[i].second;
		while (!a.empty() && a.front().first < x) {
			dmg += a.front().second;
			a.pop();
		}
		h -= dmg;
		if (h <= 0)
			continue;
		b = h / k + min(h % k, 1ll);
		a.push(make_pair(x + w, -b * k));
		dmg += b * k;
		ans += b;
	}
	cout << ans << "\n";
	return 0;
}