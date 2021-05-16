#pragma GCC optimize("O3")
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
#define INF 1 << 31

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, j, k, x, y, ans = 0;
	cin >> x >> y >> num;
	vector<int> t(num), h(num);
	vector<vector<int>> dp(x + 1, vector<int>(x + y + 1, 0));
	rep(i, num) {
		cin >> t[i] >> h[i];
	}
	rep(k, num) {
		for(i = x - 1; i >= 0; i--) {
			rep(j, x + y - t[k] + 1) {
				chmax(dp[i + 1][j + t[k]], dp[i][j] + h[k]);
			}
		}
	}
	rep(i, x + 1) {
		chmax(ans, dp[i][x + y]);
	}
	cout << ans << "\n";
	return 0;
}