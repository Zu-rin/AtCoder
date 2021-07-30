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

void BFS(vector<vector<int>> &d, vector<ll> &ans) {
	queue<pp> que;
	vector<int> cost(d.size(), INF);
	que.push(pp(1, 0));
	while (!que.empty()) {
		int n = que.front().first;
		int c = que.front().second;
		que.pop();
		if (cost[n] == INF) {
			cost[n] = c++;
			for (int nx : d[n]) {
				if (cost[nx] == INF)
					que.push(pp(nx, c));
			}
		}
	}
	vector<int> ok(d.size() + 1, 0);
	ans[1] = 1;
	que.push(pp(1, 0));
	while (!que.empty()) {
		int n = que.front().first;
		que.pop();
		if (!ok[n]) {
			for (int nx : d[n]) {
				if (cost[n] + 1 == cost[nx]) {
					que.push(pp(nx, 0));
					ans[nx] += ans[n];
					if (MOD <= ans[nx])
						ans[nx] -= MOD;
				}
			}
		}
		ok[n] = 1;
	}
}

int main(void) {
	int num, m, i, a, b;
	cin >> num >> m;
	vector<ll> ans(num + 1, 0);
	vector<vector<int>> d(num + 1);
	rep(i, m) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	BFS(d, ans);
	cout << ans[num] << "\n";
	return 0;
}