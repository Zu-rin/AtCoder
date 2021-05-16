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
#define INF 1 << 29

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

void Search(int s, vector<vector<int>> &d, vector<int> & ans) {
	queue<pp> que;
	que.push({ s, 0 });
	while (!que.empty()) {
		int n = que.front().first, c = que.front().second;
		que.pop();
		if (ans[n] == INF) {
			ans[n] = c;
			for (int nx : d[n]) {
				if (ans[nx] == INF) {
					que.push({ nx, c + 1 });
				}
			}
		}
	}
}

int main(void) {
	int num, m, i, j, n, a, b, k, ans = INF;
	cin >> num >> m;
	vector<vector<int>> e(num + 1);
	rep(i, m) {
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	cin >> k;
	vector<int> x(k);
	vector<vector<int>> d(k, vector<int>(num + 1, INF)), dp(1 << k, vector<int>(k, INF));
	rep(i, k) {
		cin >> x[i];
		Search(x[i], e, d[i]);
		dp[1 << i][i] = 1;
	}
	rep(i, 1 << k) {
		rep(j, k) {
			rep(n, k) {
				chmin(dp[i | (1 << n)][n], dp[i][j] + d[j][x[n]]);
			}
		}
	}
	rep(i, k) {
		chmin(ans, dp[(1 << k) - 1][i]);
	}
	if (ans == INF)
		printf("-1\n");
	else
		cout << ans << "\n";
	return 0;
}