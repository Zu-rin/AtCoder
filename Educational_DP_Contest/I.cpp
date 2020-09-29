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
	int num, i, j;
	double ans = 0.0;
	cin >> num;
	vector<double> p(num);
	rep(i, num)
		cin >> p[i];
	vector<vector<double>> dp(num + 1, vector<double>(num + 1, 0.0));
	dp[0][0] = 1.0;
	rep(i, num) {
		rep(j, i + 1) {
			dp[i + 1][j + 1] = dp[i][j] * p[i];
			dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
		}
	}
	for (i = num / 2 + 1; i <= num; i++) {
		ans += dp[num][i];
	}
	printf("%.10lf\n", ans);
	return 0;
}