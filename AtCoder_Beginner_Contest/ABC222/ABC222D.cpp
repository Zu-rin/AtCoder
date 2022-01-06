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
	int num, i, j;
	cin >> num;
	ll ans = 0;
	vector<ll> a(num), b(num);
	vector<vector<ll>> dp(num, vector<ll>(3001, 0));
	rep(i, num)
		cin >> a[i];
	rep(i, num)
		cin >> b[i];
	for (i = a[0]; i <= b[0]; i++)
		dp[0][i] = 1;
	for (i = 1; i < num; i++) {
		ll s = 0;
		rep(j, a[i]) {
			s += dp[i - 1][j];
			if (s >= MOD)
				s -= MOD;
		}
		for (j = a[i]; j <= b[i]; j++) {
			s += dp[i - 1][j];
			if (s >= MOD)
				s -= MOD;
			dp[i][j] = s;
		}
	}
	rep(i, 3001) {
		ans += dp[num - 1][i];
		if (ans >= MOD)
			ans -= MOD;
	}
	cout << ans << "\n";
	return 0;
}