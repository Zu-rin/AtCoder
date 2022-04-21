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
	ll num, m, a, ans = 0;
	int i, j;
	cin >> num >> m >> a;
	a -= num;
	vector<vector<ll>> dp(num + 1, vector<ll>(a + 1, 0));
	dp[0][0] = 1;
	rep(i, num) {
		rep(j, a)
			dp[i][j] %= MOD;
		rep(j, a + 1) {
			if (!dp[i][j])
				continue;
			for (int k = 0; k < m and j + k <= a; k++)
				dp[i + 1][j + k] += dp[i][j];
		}
	}
	rep(i, a + 1)
		ans += dp[num][i];
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}