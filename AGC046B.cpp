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

ll sx, sy;

ll Search(ll x, ll y, vector<vector<ll>> & dp) {
	if (dp[x][y])
		return dp[x][y];
	if (x < sx || y < sy)
		return 0;
	ll ans = y * Search(x - 1, y, dp) + x * Search(x, y - 1, dp) - (x - 1) * (y - 1) * Search(x - 1, y - 1, dp);
	ans %= MOD;
	if (ans < 0)
		ans += MOD;
	return dp[x][y] = ans;
}

int main(void) {
	ll num, X, Y;
	cin >> sx >> sy >> X >> Y;
	vector<vector<ll>> dp(X + 1, vector<ll>(Y + 1, 0));
	dp[sx][sy] = 1;
	for (ll i = sx; i <= X; i++) {
		for (ll j = sy; j <= Y; j++) {
			Search(i, j, dp);
		}
	}
	cout << dp[X][Y] << "\n";
	return 0;
}