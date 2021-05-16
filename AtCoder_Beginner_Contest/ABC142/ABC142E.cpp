#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, m, i, j, b, x, ma;
	cin >> num >> m;
	vector<int> a(m), k(m);
	ma = 1 << num;
	vector<vector<int>> dp(m + 1, vector<int>(ma, INF));
	for (i = 0; i < m; i++) {
		cin >> a[i] >> b;
		for (j = 0; j < b; j++) {
			cin >> x;
			k[i] += 1 << (x - 1);
		}
	}
	dp[0][0] = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < ma; j++) {
			if (dp[i][j] != INF) {
				dp[i + 1][j | k[i]] = min(dp[i + 1][j | k[i]], dp[i][j] + a[i]);
			}
		}
		for (j = 0; j < ma; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
		}
	}
	if (dp[m][ma - 1] == INF)
		printf("-1\n");
	else
		cout << dp[m][ma - 1] << "\n";
	return 0;
}