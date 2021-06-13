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
	int num, k, i;
	cin >> num >> k;
	vector<ll> dp(num + 1, 0);
	dp[0] = 1;
	rep(i, num) {
		dp[i + 1] += dp[i];
		if (i + k <= num)
			dp[i + k] += dp[i];
		dp[i + 1] %= MOD;
	}
	cout << dp[num] << "\n";
	return 0;
}