#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int main(void) {
	int h, w, k, i, j, a, b;
	cin >> h >> w >> k;
	vector<vector<ll>> dp(h + 1, vector<ll>(w, 0));
	dp[0][0] = 1;
	for (i = 0; i < h; i++) {
		for (a = 0; a < 1 << (w - 1); a++) {
			b = a;
			while (b > 0 && (b & 3) != 3)
				b >>= 1;
			if (b > 0)
				continue;
			for (j = 0; j < w; j++) {
				if (a & (1 << j)) {
					dp[i + 1][j + 1] += dp[i][j];
					dp[i + 1][j + 1] %= MOD;
				}
				else if (j > 0 && (a & (1 << (j - 1)))) {
					dp[i + 1][j - 1] += dp[i][j];
					dp[i + 1][j - 1] %= MOD;
				}
				else {
					dp[i + 1][j] += dp[i][j];
					dp[i + 1][j] %= MOD;
				}
			}
		}
	}
	cout << dp[h][k - 1] << "\n";
	return 0;
}