#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int main(void) {
	int i, j, k;
	string s;
	cin >> s;
	vector<vector<ll>> dp(s.size() + 1, vector<ll>(13, 0));
	dp[0][0] = 1;
	for (i = 0; i < s.size();) {
		switch (s[i]) {
		case '?':
			for (j = 0; j < 10; j++) {
				for (k = 0; k < 13; k++) {
					dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
				}
			}
			break;
		default:
			j = s[i] - '0';
			for (k = 0; k < 13; k++) {
				dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
			}
			break;
		}
		i++;
		for (j = 0; j < 13; j++) {
			dp[i][j] %= MOD;
		}
	}
	cout << dp[i][5] << "\n";
	return 0;
}