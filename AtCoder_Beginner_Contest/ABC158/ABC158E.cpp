#pragma GCC optimize ("O3")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, j, p, a, k = 0;
	ll ans = 0;
	string s;
	cin >> num >> p >> s;
	vector<int> dp(p, 0);
	dp[(s[0] - '0') % p] = 1;
	ans = dp[0];
	for (i = 1; i < num; i++) {
		a = s[i] - '0';
		k += a % p;
		k %= p;
		dp[a % p]++;
		ans += dp[k];
	}
	cout << ans << "\n";
	return 0;
}