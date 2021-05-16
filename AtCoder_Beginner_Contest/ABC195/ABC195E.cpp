#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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
	string s, t;
	cin >> num >> s >> t;
	vector<set<int>> dp(num + 1);
	dp[num].insert(0);
	for (i = num - 1; i >= 0; i--) {
		int x = t[i] == 'A' ? 2 : 1;
		rep(j, 7) {
			int a = (j * 10 + s[i] - '0') % 7;
			int b = (j * 10) % 7;
			if (dp[i + 1].count(a) + dp[i + 1].count(b) >= x)
				dp[i].insert(j);
		}
	}
	printf(dp[0].count(0) ? "Takahashi" : "Aoki");
	return 0;
}