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
	int num, i, g, a, t[3], k, ans;
	cin >> num >> g;
	vector<int> d(g + 10, false), dp(g + 10, INF);
	dp[0] = 0;
	rep(i, num) {
		cin >> a;
		d[a] = true;
	}
	rep(i, 3)
		cin >> t[i];
	rep(i, g) {
		chmin(dp[i + 1], dp[i] + t[0] + d[i + 1] * t[2]);
		chmin(dp[i + 2], dp[i] + t[0] + t[1] + d[i + 2] * t[2]);
		chmin(dp[i + 4], dp[i] + t[0] + 3 * t[1] + d[i + 4] * t[2]);
	}
	ans = dp[g];
	t[0] >>= 1;
	t[1] >>= 1;
	if(g >= 3)
		chmin(ans, dp[g - 3] + t[0] + t[1] * 5);
	chmin(ans, dp[g - 2] + t[0] + t[1] * 3);
	chmin(ans, dp[g - 1] + t[0] + t[1]);
	cout << ans << "\n";
	return 0;
}