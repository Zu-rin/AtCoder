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
	int num, i, a, b = 0;
	cin >> num;
	vector<ll> dp(num + 1, 0), d(200000, 0);
	dp[0] = 1;
	rep(i, num) {
		cin >> a;
		if (a == b) {
			dp[i + 1] = dp[i];
			continue;
		}
		dp[i + 1] = (dp[i] + d[a]) % MOD;
		d[a] += dp[i];
		d[a] %= MOD;
		b = a;
	}
	cout << dp[num] << "\n";
	return 0;
}