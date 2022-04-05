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
	int num, i, j, k;
	ll h, w, x1, x2, y1, y2, ans;
	cin >> h >> w >> k;
	cin >> x1 >> y1 >> x2 >> y2;
	vector<vector<ll>> dp(k + 1, vector<ll>(4, 0));
	dp[0][0] = 1;
	rep(i, k) {
		dp[i + 1][0] = dp[i][1] * (h - 1) + dp[i][2] * (w - 1);
		dp[i + 1][1] = dp[i][0] + dp[i][1] * (h - 2) + dp[i][3] * (w - 1);
		dp[i + 1][2] = dp[i][0] + dp[i][2] * (w - 2) + dp[i][3] * (h - 1);
		dp[i + 1][3] = dp[i][1] + dp[i][2] + dp[i][3] * (h + w - 4);
		rep(j, 4)
			dp[i + 1][j] %= MOD;
	}
	if (x1 == x2) {
		if (y1 == y2)
			ans = dp[k][0];
		else
			ans = dp[k][2];
	}
	else {
		if (y1 == y2)
			ans = dp[k][1];
		else
			ans = dp[k][3];
	}
	cout << ans << "\n";
	return 0;
}