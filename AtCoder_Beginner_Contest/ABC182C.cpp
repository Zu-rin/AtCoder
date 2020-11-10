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
	string s;
	cin >> s;
	vector<vector<int>> dp(3, vector<int>(s.size() + 1, -INF));
	dp[0][0] = 0;
	rep(i, s.size()) {
		int k = s[i] - '0';
		rep(j, 3) {
			int n = (j + k) % 3;
			dp[(j + k) % 3][i + 1] = max(dp[j][i] + 1, dp[(j + k) % 3][i]);
		}
	}
	int ans = s.size() - dp[0][s.size()];
	if (ans == s.size())
		printf("-1\n");
	else
		cout << ans << "\n";
	return 0;
}