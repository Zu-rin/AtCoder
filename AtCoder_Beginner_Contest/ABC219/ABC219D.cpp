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

struct Box {
	int a, b;
};

int main(void) {
	int num, i, j, k, x, y;
	cin >> num >> x >> y;
	vector<Box> d(num);
	vector<vector<int>> dp(x + 1, vector<int>(y + 1, INF));
	dp[0][0] = 0;
	rep(i, num)
		cin >> d[i].a >> d[i].b;
	rep(k, num) {
		for (i = x; i >= 0; i--) {
			for (j = y; j >= 0; j--) {
				chmin(dp[min(x, i + d[k].a)][min(y, j + d[k].b)], dp[i][j] + 1);
			}
		}
	}
	if (dp[x][y] == INF)
		printf("-1\n");
	else
		cout << dp[x][y] << "\n";
	return 0;
}