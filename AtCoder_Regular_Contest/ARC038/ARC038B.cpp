#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int h, w;

int Search(int y, int x, vector<string> &d, vector<vector<int>> &dp) {
	if (dp[y][x] >= 0)
		return dp[y][x];
	dp[y][x] = false;
	if (d[y + 1][x] == '.')
		dp[y][x] |= !Search(y + 1, x, d, dp);
	if (d[y][x + 1] == '.')
		dp[y][x] |= !Search(y, x + 1, d, dp);
	if (d[y + 1][x + 1] == '.')
		dp[y][x] |= !Search(y + 1, x + 1, d, dp);
	return dp[y][x];
}

int main(void) {
	int num, i, ok;
	cin >> h >> w;
	vector<string> d(h + 1, "");
	vector<vector<int>> dp(h, vector<int>(w, -1));
	for (i = 0; i < h; i++) {
		cin >> d[i];
		d[i] += "#";
	}
	for (i = 0; i <= w; i++)
		d[h] += "#";
	ok = Search(0, 0, d, dp);
	if (ok)
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}