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
	int num, i, j, k, a;
	cin >> num >> k;
	vector<vector<ll>> dp(num + 1, vector<ll>(k + 1, 0));
	dp[0][0] = 1;
	rep(j, num) {
		cin >> a;
		rep(i, k + 1)
			dp[j + 1][i] = (dp[j][i] << 1) % MOD;
		rep(i, k - a + 1) {
			dp[j + 1][i + a] += dp[j][i];
			dp[j + 1][i + a] %= MOD;
		}
	}
	cout << dp[num][k] << "\n";
	return 0;
}