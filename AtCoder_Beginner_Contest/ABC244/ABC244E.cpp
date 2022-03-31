#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 998244353
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int n, m, k, s, e, x, i, a, b;
	cin >> n >> m >> k >> s >> e >> x;
	vector<vector<int>> d(n + 1);
    vector<vector<vector<ll>>>	dp(k + 1, vector<vector<ll>>(n + 1, vector<ll>(2, 0)));
	dp[0][s][0] = 1;
	rep(i, m) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	rep(i, k) {
		for (int j = 1; j <= n; j++) {
			rep(a, 2) {
				if (!dp[i][j][a])
					continue;
				for (int nx : d[j]) {
					if(nx == x)
						dp[i + 1][nx][(a + 1) & 1] += dp[i][j][a];
					else
						dp[i + 1][nx][a] += dp[i][j][a];
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			dp[i + 1][j][0] %= MOD;
			dp[i + 1][j][1] %= MOD;
		}
	}
	cout << dp[k][e][0] << "\n";
	return 0;
}