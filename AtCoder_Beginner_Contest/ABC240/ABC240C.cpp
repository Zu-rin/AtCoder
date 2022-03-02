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
	int num, i, j, x;
	cin >> num >> x;
	vector<int> a(num), b(num);
	vector<vector<char>> dp(num + 1, vector<char>(x + 1, 0));
	dp[0][0] = 1;
	rep(i, num)
		cin >> a[i] >> b[i];
	rep(i, num) {
		rep(j, dp[i].size()) {
			if (dp[i][j]) {
				if (j + a[i] <= x)
					dp[i + 1][j + a[i]] = 1;
				if (j + b[i] <= x)
					dp[i + 1][j + b[i]] = 1;
			}
		}
	}
	if (dp[num][x])
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}