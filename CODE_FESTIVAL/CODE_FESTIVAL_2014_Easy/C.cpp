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

void Search(int s, vector<list<pp>> &d, vector<int> & ans) {
	int n, w;
	priority_queue<pp, vector<pp>, greater<pp>> que;
	que.push(pp(0, s));
	while (!que.empty()) {
		w = que.top().first;
		n = que.top().second;
		que.pop();
		if (ans[n] <= w)
			continue;
		ans[n] = w;
		for (auto it = d[n].begin(); it != d[n].end(); it++) {
			if (ans[(*it).second] == INF) {
				auto a = *it;
				a.first += ans[n];
				que.push(a);
			}
		}
	}
	return;
}

int main(void) {
	int n, m, i, s, g, a, b, c, ans = -1;
	cin >> n >> m >> s >> g;
	vector<list<pp>> d(n + 1);
	rep(i, m) {
		cin >> a >> b >> c;
		d[a].push_back(pp(c, b));
		d[b].push_back(pp(c, a));
	}
	vector<int> x(n + 1, INF), y(n + 1, INF);
	Search(s, d, x);
	Search(g, d, y);
	for (i = 1; i <= n; i++) {
		if (x[i] != INF && x[i] == y[i]) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}