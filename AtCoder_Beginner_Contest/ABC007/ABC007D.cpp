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

ll Solve(const string& s) {
	int i;
	ll dp[20][2][2] = {0}, d[10] = { 0,1,2,3,4,4,5,6,7,8 };
	dp[0][0][0] = 1;
	rep(i, s.size()) {
		int n = s[i] - '0';
		if (dp[i][0][1] == 1 || n == 4 || n == 9)
			dp[i + 1][0][1] = 1;
		else
			dp[i + 1][0][0] = 1;
		dp[i + 1][1][0] = dp[i][1][0] * 8 + dp[i][0][0] * d[n];
		dp[i + 1][1][1] = dp[i][1][0] * 2 + dp[i][1][1] * 10 + dp[i][0][1] * n;
		if (n > 4)
			dp[i + 1][1][1] += dp[i][0][0];
	}
	return dp[i][0][1] + dp[i][1][1];
}

int main(void) {
	int num, i;
	ll ans;
	string a, b;
	cin >> ans >> b;
	a = to_string(ans - 1);
	ans = Solve(b);
	ans -= Solve(a);
	cout << ans << "\n";
	return 0;
}