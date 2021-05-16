#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1 << 20

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	int num, x, y, i, j, k, a, b, c, m, ans = INF;
	cin >> num >> x >> y;
	m = num * 10;
	vector<vector<vector<int>>> dp(num + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 0)));
	for (i = 0; i < num; i++) {
		for (j = 1; j <= m; j++) {
			for (k = 1; k <= m; k++) {
				dp[i + 1][j][k] = dp[i][j][k];
			}
		}
		scanf_s("%d%d%d", &a, &b, &c);
		if (dp[i + 1][a][b] == 0)
			dp[i + 1][a][b] = c;
		else
			dp[i + 1][a][b] = min(dp[i + 1][a][b], c);
		for (j = 1; j <= m - a; j++) {
			for (k = 1; k <= m - b; k++) {
				if (dp[i][j][k] > 0) {
					if (dp[i + 1][j + a][k + b] == 0)
						dp[i + 1][j + a][k + b] = dp[i][j][k] + c;
					else
						dp[i + 1][j + a][k + b] = min(dp[i + 1][j + a][k + b], dp[i][j][k] + c);
				}
			}
		}
	}
	a = x;
	b = y;
	while (a <= m && b <= m) {
		if (dp[num][a][b] > 0)
			ans = min(ans, dp[num][a][b]);
		a += x;
		b += y;
	}
	if (ans < INF)
		cout << ans << "\n";
	else
		printf("-1\n");
	return 0;
}