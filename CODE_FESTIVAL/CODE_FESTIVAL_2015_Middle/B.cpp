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

int Judge(string & s, string & t) {
	int i, j;
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
	rep(i, s.size()) {
		rep(j, t.size()) {
			if (s[i] == t[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}
	return s.size() + t.size() - 2 * dp[s.size()][t.size()];
}

int main(void) {
	int i, j, num, ans = INF;
	string s;
	cin >> num >> s;
	rep(i, s.size()) {
		string a = s.substr(0, i), b = s.substr(i);
		chmin(ans, Judge(a, b));
	}
	cout << ans << "\n";
	return 0;
}