#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<int, ll> pp;

int main(void) {
	int num, i, j, m, a, b;
	cin >> num >> m;
	vector<ll> x(num), y(num + 1, 0), d(num + 1, 0);
	vector<vector<ll>> dp(num + 1, vector<ll>(num + 1, -INF));
	vector<pp> k(m);
	dp[0][0] = 0;
	rep(i, num)
		cin >> x[i];
	rep(i, m) {
		cin >> a >> b;
		y[a] = b;
	}
	sort(k.begin(), k.end());
	rep(i, num) {
		rep(j, num) {
			dp[i + 1][j + 1] = dp[i][j] + x[i] + y[j + 1];
			chmax(dp[i + 1][0], dp[i][j]);
		}
	}
	ll ans = 0;
	rep(i, num + 1)
		chmax(ans, dp[num][i]);
	cout << ans << "\n";
	return 0;
}