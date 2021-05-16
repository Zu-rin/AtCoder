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

void Search(int n, vector<vector<int>> & d, vector<vector<ll>> & dp) {
	if (dp[n][0] >= 0)
		return;
	int i;
	dp[n][0] = dp[n][1] = 1;
	rep(i, d[n].size()) {
		int& nx = d[n][i];
		if (dp[nx][0] < 0) {
			Search(nx, d, dp);
			dp[n][0] *= dp[nx][0] + dp[nx][1];
			dp[n][1] *= dp[nx][0];
			dp[n][0] %= MOD;
			dp[n][1] %= MOD;
		}
	}
	return;
}

int main(void) {
	int num, i, a, b;
	cin >> num;
	vector<vector<int>> d(num + 1);
	vector<vector<ll>> dp(num + 1, vector<ll>(2, -1));
	rep(i, num - 1) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	Search(1, d, dp);
	ll ans = (dp[1][0] + dp[1][1]) % MOD;
	cout << ans << "\n";
	return 0;
}