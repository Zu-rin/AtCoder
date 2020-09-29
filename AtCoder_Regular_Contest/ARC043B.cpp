#include<bits/stdc++.h>
#define rep(i, n) for(i = 0; i < (n); i++)
#define MOD 1000000007

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j, a;
	ll ans = 0;
	cin >> num;
	ll dp[4][100001] = { 0 };
	rep(i, num) {
		scanf("%d", &a);
		dp[0][a]++;
	}
	rep(i, 3) {
		ll d[100001] = { 0 };
		rep(j, 100000)
			d[j + 1] = (dp[i][j + 1] + d[j]) % MOD;
		rep(j, 100001)
			dp[i + 1][j] = d[j >> 1] * dp[0][j] % MOD;
	}
	rep(j, 100001) {
		ans += dp[3][j];
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}