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
	vector<ll> d(num);
	vector<vector<ll>> dp(num, vector<ll>(10, 0));
	rep(i, num)
		cin >> d[i];
	dp[0][d[0]] = 1;
	rep(i, num - 1) {
		rep(j, 10) {
			dp[i][j] %= MOD;
			dp[i + 1][(d[i + 1] + j) % 10] += dp[i][j];
			dp[i + 1][(d[i + 1] * j) % 10] += dp[i][j];
		}
	}
	rep(i, 10)
		cout << dp[num - 1][i] % MOD << "\n";
	return 0;
}