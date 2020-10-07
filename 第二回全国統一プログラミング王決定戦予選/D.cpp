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
			vector<pp>& e = d[n];
			rep(i, e.size()) {
				if (ans[e[i].second] == INF) {
					que.push(pp(e[i].first + c, e[i].second));
				}
			}
		}
	}
	return;
}

int main(void) {
	int num, m, i, l, r;
	ll c;
	cin >> num >> m;
	vector<vector<pp>> d(num + 1);
	vector<ll> ans(num + 1, INF);
	rep(i, num) {
		d[i + 1].push_back(pp(0, i));
	}
	rep(i, m) {
		cin >> l >> r >> c;
		d[l].push_back(pp(c, r));
		d[r].push_back(pp(c, l));
	}
	Dijk(1, d, ans);
	if (ans[num] == INF)
		printf("-1\n");
	else
		cout << ans[num] << "\n";
	return 0;
}