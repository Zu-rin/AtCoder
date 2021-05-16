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
	int num, i, j, k, ans;
	string s;
	cin >> s >> k;
	vector<vector<vector<int>>> dp(s.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
	dp[0][0][0] = 1;
	rep(i, s.size()) {
		if (s[i] == '0') {
			rep(j, k + 1) {
				dp[i + 1][j][0] = dp[i][j][0];
				dp[i + 1][j][1] = dp[i][j][1];
			}
			rep(j, k) {
				dp[i + 1][j + 1][1] += 9 * dp[i][j][1];
			}
		}
		else {
			rep(j, k + 1) {
				dp[i + 1][j][1] = dp[i][j][0] + dp[i][j][1];
			}
			rep(j, k) {
				dp[i + 1][j + 1][0] = dp[i][j][0];
				dp[i + 1][j + 1][1] += (s[i] - '1') * dp[i][j][0] + 9 * dp[i][j][1];
			}
		}
	}
	ans = dp[s.size()][k][0] + dp[s.size()][k][1];
	cout << ans << "\n";
	return 0;
}