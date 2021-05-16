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
typedef struct {
	int l, r;
} area;

int main(void) {
	int num, i, j, k;
	cin >> num >> k;
	vector<ll> dp(num + 2, 0);
	vector<area> a(k);
	rep(i, k)
		cin >> a[i].l >> a[i].r;
	dp[1] = 1;
	dp[2] = -1;
	for (i = 1; i < num; i++) {
		rep(j, k) {
			dp[min(i + a[j].l, num + 1)] += dp[i];
			dp[min(i + a[j].r + 1, num + 1)] -= dp[i];
		}
		dp[i + 1] += dp[i];
		dp[i + 1] %= MOD;
	}
	if (dp[num] < 0)
		dp[num] += MOD;
	cout << dp[num] << "\n";
	return 0;
}