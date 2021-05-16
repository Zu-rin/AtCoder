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
	int num, i, j, k, r, c, a, b, v;
	ll ans = 0;
	cin >> r >> c >> num;
	vector<vector<vector<ll>>> dp(r + 1, vector<vector<ll>>(c + 1, vector<ll>(4, 0)));
	vector<vector<ll>> d(r + 1, vector<ll>(c + 1, 0));
	rep(i, num) {
		cin >> a >> b;
		cin >> d[a][b];
	}
	for (i = 1; i <= r; i++) {
		for (j = 1; j <= c; j++) {
			rep(k, 4)
				dp[i][j][k] = max(dp[i][j - 1][k], dp[i - 1][j][3]);
			for (k = 3; k > 0; k--)
				chmax(dp[i][j][k], dp[i][j][k - 1] + d[i][j]);
		}
	}
	cout << dp[r][c][3] << "\n";
	return 0;
}