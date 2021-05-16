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
	int n, m, i, j;
	cin >> n >> m;
	vector<int> a(n), b(m);
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 1)), sum(n + 1, vector<ll>(m + 1, 0));
	rep(i, n)
		cin >> a[i];
	rep(i, m)
		cin >> b[i];
	rep(i, n) {
		rep(j, m) {
			dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
			if (a[i] == b[j])
				dp[i + 1][j + 1] += dp[i][j];
			dp[i + 1][j + 1] += MOD;
			dp[i + 1][j + 1] %= MOD;
		}
	}
	cout << dp[n][m] << "\n";
	return 0;
}