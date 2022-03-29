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
	int num, i, j, k;
	cin >> num >> k;
	vector<vector<int>> ab(num, vector<int>(2)), dp(num, vector<int>(2, 0));
	rep(j, 2) {
		rep(i, num)
			cin >> ab[i][j];
	}
	dp[0][0] = dp[0][1] = 1;
	rep(i, num - 1) {
		rep(j, 2) {
			if (dp[i][j]) {
				dp[i + 1][0] |= abs(ab[i][j] - ab[i + 1][0]) <= k;
				dp[i + 1][1] |= abs(ab[i][j] - ab[i + 1][1]) <= k;
			}
		}
	}
	if (dp[num - 1][0] or dp[num - 1][1])
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}