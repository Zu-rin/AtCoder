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
	string s, c = "chokudai";
	cin >> s;
	vector<ll> dp(8, 0);
	rep(i, s.size()) {
		for (j = 7; j > 0; j--) {
			if (s[i] == c[j]) {
				dp[j] += dp[j - 1];
				dp[j] %= MOD;
			}
		}
		if (s[i] == 'c')
			dp[0]++;
	}
	cout << dp[7] << "\n";
	return 0;
}