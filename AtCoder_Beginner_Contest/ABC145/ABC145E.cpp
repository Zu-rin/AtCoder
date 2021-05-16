#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, j, t, ans = 0, x;
	cin >> num >> t;
	vector<vector<int>> dp(num + 1, vector<int>(t, 0));
	vector<pp> a(num);
	rep(i, num) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	rep(i, num) {
		rep(j, t) {
			x = j + a[i].first;
			if (x < t)
				dp[i + 1][x] = dp[i][j] + a[i].second;
			chmax(dp[i + 1][j], dp[i][j]);
		}
		chmax(ans, dp[i][t - 1] + a[i].second);
	}
	cout << ans << "\n";
	return 0;
}