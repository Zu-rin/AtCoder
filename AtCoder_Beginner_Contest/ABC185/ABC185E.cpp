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

int main(void) {
	int n, m, i, j, ans = INF;
	cin >> n >> m;
	vector<int> a(n), b(m);
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)), x(n + 1, vector<int>(m + 1, 0)), y(n + 1, vector<int>(m + 1, 0));
	rep(i, n)
		cin >> a[i];
	rep(i, n + 1)
		x[i][0] = y[i][0] = i;
	rep(i, m)
		cin >> b[i];
	rep(i, m + 1)
		x[0][i] = y[0][i] = i;
	rep(i, n) {
		rep(j, m) {
			dp[i + 1][j + 1] = min(x[i][j], y[i][j]) + (a[i] == b[j] ? 0 : 1);
			x[i + 1][j + 1] = min(x[i + 1][j] + 1, dp[i + 1][j + 1]);
			y[i + 1][j + 1] = min(y[i][j + 1] + 1, dp[i + 1][j + 1]);
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			chmin(ans, dp[i][j] + n + m - i - j);
		}
	}
	cout << ans << "\n";
	return 0;
}