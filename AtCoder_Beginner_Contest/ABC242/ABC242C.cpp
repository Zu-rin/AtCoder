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
	int num, i, ans = 0;
	cin >> num;
	vector<vector<int>> dp(num, vector<int>(11, 0));
	rep(i, 11)
		dp[0][i] = 1;
	rep(i, num - 1) {
		for (int j = 1; j <= 9; j++) {
			for (int k = -1; k <= 1; k++) {
				dp[i + 1][j + k] += dp[i][j];
				if (dp[i + 1][j + k] >= MOD)
					dp[i + 1][j + k] -= MOD;
			}
		}
	}
	for (i = 1; i <= 9; i++) {
		ans += dp[num - 1][i];
		if (ans >= MOD)
			ans -= MOD;
	}
	cout << ans << "\n";
	return 0;
}