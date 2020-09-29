#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int Pow(int n, int k) {
	int i, ans = 1;
	for (i = 0; i < k; i++) {
		ans *= n;
	}
	return ans;
}

int main(void) {
	int num, i, j, k, x, ans = 0;
	string s;
	cin >> num >> s;
	vector<vector<vector<int>>> dp(num + 1, vector<vector<int>>(3, vector<int>(1000, 0)));
	for (k = 1; k <= num; k++) {
		x = s[k - 1] - '0';
		dp[k][0][x] = true;
		for (i = 1; i < 3; i++) {
			for (j = 0; j < Pow(10, i); j++) {
				dp[k][i][j * 10 + x] |= dp[k - 1][i - 1][j];
			}
		}
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 1000; j++) {
				dp[k][i][j] |= dp[k - 1][i][j];
			}
		}
	}
	for (i = 0; i < 1000; i++) {
		if (dp[num][2][i])
			ans++;
	}
	cout << ans << "\n";
	return 0;
}