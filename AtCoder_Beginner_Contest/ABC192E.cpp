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
typedef pair<ll, int> pp;
struct train{
	int to;
	ll k, t;
};

void Dijk(int s, vector<vector<train>>& d, vector<ll>& ans) {
	priority_queue<pp, vector<pp>, greater<pp>> que;
	que.push(pp(0, s));
	while (!que.empty()) {
		ll c = que.top().first;
		int n = que.top().second;
		que.pop();
		if (ans[n] == INF) {
			ans[n] = c;
			for (train& a : d[n]) {
				if (ans[a.to] == INF) {
					ll nc = (c + a.k - 1) / a.k * a.k + a.t;
					que.push(pp(nc, a.to));
				}
			}
		}
	}
	return;
}

int main(void) {
	int num, m, i, s, g, a, b, k, t;
	cin >> num >> m >> s >> g;
	vector<vector<train>> d(num + 1);
	vector<ll> ans(num + 1, INF);
	rep(i, m) {
		cin >> a >> b >> t >> k;
		d[a].push_back({ b, k, t });
		d[b].push_back({ a, k, t });
	}
	Dijk(s, d, ans);
	if (ans[g] == INF)
		printf("-1\n");
	else
		cout << ans[g] << "\n";
	return 0;
}