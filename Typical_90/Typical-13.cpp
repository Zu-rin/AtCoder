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

void Dijk(int s, vector<vector<pp>> &d, vector<int> &ans) {
	priority_queue<pp, vector<pp>, greater<pp>> que;
	que.push(pp(0, s));
	while (!que.empty()) {
		int n = que.top().second, c = que.top().first;
		que.pop();
		if (ans[n] != INF)
			continue;
		ans[n] = c;
		for (pp& nx : d[n]) {
			if (ans[nx.second] == INF) {
				que.push(pp(c + nx.first, nx.second));
			}
		}
	}
}

int main(void) {
	int num, m, i, a, b, c;
	cin >> num >> m;
	vector<vector<pp>> d(num + 1);
	vector<int> x(num + 1, INF), y(num + 1, INF);
	rep(i, m) {
		cin >> a >> b >> c;
		d[a].push_back(pp(c, b));
		d[b].push_back(pp(c, a));
	}
	Dijk(1, d, x);
	Dijk(num, d, y);
	for (i = 1; i <= num; i++) {
		cout << x[i] + y[i] << "\n";
	}
	return 0;
}