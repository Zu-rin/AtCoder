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

void DFS(vector<char> &c, vector<vector<int>> &d, vector<vector<ll>> &dp, int n = 0, int p = 0) {
	ll x = 1;
	dp[n][c[n] == 'a'] = 0;
	for (int nx : d[n]) {
		if (nx != p) {
			DFS(c, d, dp, nx, n);
			if (c[n] == 'a') {
				dp[n][0] *= dp[nx][2] + dp[nx][0];
				dp[n][0] %= MOD;
				x *= dp[nx][0] + dp[nx][2];
				x %= MOD;
			}
			else {
				dp[n][1] *= dp[nx][2] + dp[nx][1];
				dp[n][1] %= MOD;
				x *= dp[nx][1] + dp[nx][2];
				x %= MOD;
			}
			dp[n][2] *= dp[nx][0] + dp[nx][1] + 2 * dp[nx][2];
			dp[n][2] %= MOD;
		}
	}
	dp[n][2] -= x;
	if (n and d[n].size() == 1)
		dp[n][2] = 0;
}

int main(void) {
	int num, i, a, b;
	cin >> num;
	vector<char> c(num);
	vector<vector<int>> d(num);
	vector<vector<ll>> dp(num, vector<ll>(3, 1));
	rep(i, num)
		cin >> c[i];
	rep(i, num - 1) {
		cin >> a >> b;
		d[--a].push_back(--b);
		d[b].push_back(a);
	}
	DFS(c, d, dp);
	if (dp[0][2] < 0)
		dp[0][2] += MOD;
	cout << dp[0][2] << "\n";
	return 0;
}