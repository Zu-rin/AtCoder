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
typedef pair<char, int> pp;

int main(void) {
	int num, i, s, a, b;
	cin >> num >> s;
	vector<vector<pp>> dp(num + 1, vector<pp>(s + 1, pp(0, 0)));
	dp[0][0] = pp('S', 0);
	rep(i, num) {
		cin >> a >> b;
		for (int j = s - a; j >= 0; j--) {
			if (dp[i][j].first)
				dp[i + 1][j + a] = pp('A', j);
		}
		for (int j = s - b; j >= 0; j--) {
			if (dp[i][j].first)
				dp[i + 1][j + b] = pp('B', j);
		}
	}
	if (dp[num][s].first) {
		string ans = "";
		int j = s;
		for (i = num; i > 0; i--) {
			ans += dp[i][j].first;
			j = dp[i][j].second;
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
	else
		printf("Impossible\n");
	return 0;
}