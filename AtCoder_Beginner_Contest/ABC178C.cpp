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
	int num, i, j;
	cin >> num;
	vector<vector<ll>> dp(num + 1, vector<ll>(4, 0));
	dp[0][0] = 1;
	rep(i, num) {
		dp[i + 1][0] = dp[i][0] * 8 % MOD;
		dp[i + 1][1] = (dp[i][0] + dp[i][1] * 9) % MOD;
		dp[i + 1][2] = (dp[i][0] + dp[i][2] * 9) % MOD;
		dp[i + 1][3] = (dp[i][1] + dp[i][2] + dp[i][3] * 10) % MOD;
	}
	cout << dp[num][3] << "\n";
	return 0;
}