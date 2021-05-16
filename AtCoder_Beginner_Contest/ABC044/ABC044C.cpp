#include <iostream>
#include <vector>
#define LIM 2500
#define MAX 5001

using namespace std;

int main(void) {
	int num, ave, i = 0, j;
	cin >> num >> ave;
	vector<vector<long long>> dp(num, vector<long long>(MAX));
	vector<int> d(num);
	for (; i < num; i++) {
		cin >> d[i];
		d[i] -= ave;
	}
	dp[0][d[0] + LIM]++;
	dp[0][LIM]++;
	for (i = 1; i < num; i++) {
		for (j = 0; j < d[i]; j++)
			dp[i][j] = dp[i - 1][j];
		for (; j < MAX + d[i]; j++) {
			if (j == MAX)
				break;
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - d[i]];
		}
		for (; j < MAX; j++)
			dp[i][j] = dp[i - 1][j];
	}
	cout << dp[num - 1][LIM] - 1 << "\n";
	return 0;
}