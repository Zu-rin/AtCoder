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
	int num, i, j, h, w;
	cin >> h >> w;
	vector<string> mp(h + 1);
	vector<vector<ll>> dp(h + 1, vector<ll>(w + 1, 0));
	rep(i, h) {
		cin >> mp[i];
		mp[i] += "#";
	}
	mp[h] = string(w + 1, '#');
	dp[0][0] = 1;
	rep(i, h) {
		rep(j, w) {
			dp[i][j] %= MOD;
			dp[i][j + 1] += mp[i][j + 1] == '.' ? dp[i][j] : 0;
			dp[i + 1][j] += mp[i + 1][j] == '.' ? dp[i][j] : 0;

		}
	}
	cout << dp[h - 1][w - 1] << "\n";
	return 0;
}