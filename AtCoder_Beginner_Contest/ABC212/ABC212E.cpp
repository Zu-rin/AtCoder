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
	int num, m, k, a, b, i;
	cin >> num >> m >> k;
	vector<vector<int>> d(num + 1);
	vector<vector<ll>> dp(k + 1, vector<ll>(num + 1, 0));
	rep(i, m) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	rep(i, num + 1)
		d[i].push_back(i);
	dp[0][1] = 1;
	rep(i, k) {
		ll s = 0;
		for (int j = 1; j <= num; j++)
			s += dp[i][j];
		s %= MOD;
		for (int j = 1; j <= num; j++) {
			ll b = 0;
			for (int nx : d[j])
				b += dp[i][nx];
			b %= MOD;
			dp[i + 1][j] = s - b;
			if (dp[i + 1][j] < 0)
				dp[i + 1][j] += MOD;
		}
	}
	cout << dp[k][1] << "\n";
	return 0;
}