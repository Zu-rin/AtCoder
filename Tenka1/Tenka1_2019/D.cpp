#include <iostream>
#include <vector>
#define MOD 998244353
using namespace std;
typedef long long ll;

ll Expow(ll a, int d) {
	ll ans = 1;
	while (d > 0) {
		if ((d & 1) == 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		d >>= 1;
	}
	return ans;
}

int main(void) {
	int num, wid, i, j, a, sum;
	ll A = 0, B = 0, All;
	cin >> num >> sum;
	All = Expow(3LL, num);
	wid = 300 * num + 1;
	vector<int> d(num);
	vector<vector<int>> dp(num, vector<int>(wid, 0));
	d[0] = sum;
	dp[0][0] = 2;
	dp[0][d[0]] = 1;
	for (i = 0; i < num - 1; i++) {
		scanf_s("%d", &a);
		d[i + 1] = a;
		sum += a;
		for (j = 0; j <= sum; j++) {
			if (dp[i][j] == 0)
				continue;
			dp[i + 1][j] += (dp[i][j] << 1) % MOD;
			dp[i + 1][j] %= MOD;
			dp[i + 1][j + a] = dp[i][j];
		}
	}
	for (i = (sum >> 1) + (sum & 1); i <= sum; i++)
		A = (A + dp[num - 1][i]) % MOD;
	A = 3 * A % MOD;

	if ((sum & 1) == 0) {
		vector<vector<int>> dp(num, vector<int>(wid, 0));
		sum = d[0];
		dp[0][0] = 1;
		dp[0][d[0]] = 1;
		for (i = 0; i < num - 1; i++) {
			sum += d[i + 1];
			for (j = 0; j <= sum; j++) {
				if (dp[i][j] == 0)
					continue;
				dp[i + 1][j] += dp[i][j];
				dp[i + 1][j] %= MOD;
				dp[i + 1][j + d[i + 1]] = dp[i][j];
			}
		}
		B = dp[num - 1][sum >> 1];
		B = 3 * B % MOD;
	}
	All = (All - A + B + MOD) % MOD;
	cout << All << "\n";
	return 0;
}