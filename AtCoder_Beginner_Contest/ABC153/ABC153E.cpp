#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 28

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int h, num, i, j, a, b, m;
	cin >> h >> num;
	vector<vector<int>> dp(num + 1, vector<int>(h + 1, INF));
	dp[0][0] = 0;
	rep(i, num) {
		cin >> a >> b;
		rep(j, h + 1) {
			dp[i + 1][j] = min(dp[i][j], min(dp[i + 1][max(0, j - a)], dp[i][max(0, j - a)]) + b);
		}
	}
	cout << dp[num][h] << "\n";
	return 0;
}