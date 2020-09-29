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
	int w, num, t, i, j, k, a, b, ans = 0;
	cin >> w >> num >> t;
	vector<vector<int>> dp(t + 1, vector<int>(w + 1, 0));
	rep(i, num) {
		cin >> a >> b;
		for (j = t - 1; j >= 0; j--) {
			rep(k, w - a + 1)
				chmax(dp[j + 1][k + a], dp[j][k] + b);
		}
	}
	rep(i, t + 1) {
		rep(j, w + 1)
			chmax(ans, dp[i][j]);
	}
	cout << ans << "\n";
 	return 0;
}