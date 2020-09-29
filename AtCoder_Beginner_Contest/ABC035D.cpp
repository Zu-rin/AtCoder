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
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<ll, int> pp;

void Dijk(int s, vector<vector<pp>> &d, vector<ll> &ans) {
	int i;
	priority_queue<pp, vector<pp>, greater<pp>> que;
	que.push(pp(0, s));
	while (!que.empty()) {
		ll c = que.top().first;
		int n = que.top().second;
		que.pop();
		if (ans[n] == INF) {
			ans[n] = c;
			rep(i, d[n].size()) {
				pp a = d[n][i];
				if (ans[a.second] == INF) {
					a.first += c;
					que.push(a);
				}
			}
		}
	}
	return;
}

int main(void) {
	int num, m, i, a, b;
	ll c, t, ans = 0;
	cin >> num >> m >> t;
	vector<ll> d(num), x(num, INF), y(num, INF);
	vector<vector<pp>> e(num), r(num);
	rep(i, num)
		cin >> d[i];
	rep(i, m) {
		cin >> a >> b >> c;
		a--; b--;
		e[a].push_back(pp(c, b));
		r[b].push_back(pp(c, a));
	}
	Dijk(0, e, x);
	Dijk(0, r, y);
	rep(i, num) {
		if(x[i] != INF && y[i] != INF)
			chmax(ans, d[i] * (t - x[i] - y[i]));
	}
	cout << ans << "\n";
	return 0;
}