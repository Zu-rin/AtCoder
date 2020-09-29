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

int num;
double Search(vector<vector<vector<double>>> &dp, int a, int b, int c) {
	if (dp[a][b][c] >= 0.0)
		return dp[a][b][c];
	double x = (double)num;
	if (a)
		x += (double)a * Search(dp, a - 1, b, c);
	if (b)
		x += (double)b * Search(dp, a + 1, b - 1, c);
	if (c)
		x += (double)c * Search(dp, a, b + 1, c - 1);
	return dp[a][b][c] = x / (double)(a + b + c);
}

int main(void) {
	int i, k;
	double ans;
	vector<int> a(4, 0);
	cin >> num;
	rep(i, num) {
		cin >> k;
		a[k]++;
	}
	vector<vector<vector<double>>> dp(num + 1, vector<vector<double>>(num + 1, vector<double>(num + 1, -1.0)));
	dp[0][0][0] = 0.0;
	ans = Search(dp, a[1], a[2], a[3]);
	printf("%.10lf\n", ans);
	return 0;
}