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
	int num, i;
	ll ans = 0;
	cin >> num;
	vector<ll> d(num);
	vector<vector<ll>> dp(num, vector<ll>(2, 0));
	rep(i, num)
		cin >> d[i];
	if (num == 1) {
		cout << d[0] << "\n";
		return 0;
	}
	dp[1][0] = dp[1][1] = 1;
	for(i = 1; i < num - 1; i++) {
		dp[i + 1][0] = dp[i][0] + dp[i][1];
		if (dp[i + 1][0] >= MOD)
			dp[i + 1][0] -= MOD;
		dp[i + 1][1] = dp[i][0];
	}
	for (i = 1; i <= num / 2; i++) {
		dp[i][0] = dp[num - i][0] = dp[i][0] * dp[num - i][0] % MOD;
		dp[i][1] = dp[num - i][1] = dp[i][1] * dp[num - i][1] % MOD;
	}
	dp[0][0] = (dp[1][0] + dp[1][1]) % MOD;
	rep(i, num) {
		ans += d[i] * (dp[i][0] - dp[i][1]) % MOD;
		ans %= MOD;
	}
	if (ans < 0)
		ans += MOD;
	cout << ans << "\n";
	return 0;
}