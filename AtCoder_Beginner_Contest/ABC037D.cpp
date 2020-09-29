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

int h, w;
ll Search(int i, int j, vector<vector<ll>> & mp, vector<vector<ll>> & dp) {
	if (dp[i][j])
		return dp[i][j];
	ll ans = 1;
	if (i > 0 && mp[i][j] < mp[i - 1][j]) {
		ans += Search(i - 1, j, mp, dp);
		ans %= MOD;
	}
	if (j > 0 && mp[i][j] < mp[i][j - 1]) {
		ans += Search(i, j - 1, mp, dp);
		ans %= MOD;
	}
	if (i < h - 1 && mp[i][j] < mp[i + 1][j]) {
		ans += Search(i + 1, j, mp, dp);
		ans %= MOD;
	}
	if (j < w - 1 && mp[i][j] < mp[i][j + 1]) {
		ans += Search(i, j + 1, mp, dp);
		ans %= MOD;
	}
	return dp[i][j] = ans;
}

int main(void) {
	int num, i, j;
	ll ans = 0;
	cin >> h >> w;
	vector<vector<ll>> mp(h, vector<ll>(w)), dp(h, vector<ll>(w, 0));
	rep(i, h) {
		rep(j, w)
			cin >> mp[i][j];
	}
	rep(i, h) {
		rep(j, w) {
			if (dp[i][j])
				ans += dp[i][j];
			else
				ans += Search(i, j, mp, dp);
			ans %= MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}