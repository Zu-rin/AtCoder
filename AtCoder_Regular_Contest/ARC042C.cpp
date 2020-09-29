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
	int num, i, j, lim, ans = 0;
	cin >> num >> lim;
	vector<int> dp(lim + 101, 0);
	vector<pp> d(num);
	rep(i, num) {
		cin >> d[i].first >> d[i].second;
	}
	sort(d.begin(), d.end(), greater<pp>());
	rep(i, num) {
		for (j = dp.size() - 1 - d[i].first; j >= 0; j--) {
			chmax(dp[j + d[i].first], dp[j] + d[i].second);
		}
		chmax(ans, dp[lim + d[i].first]);
	}
	cout << ans << "\n";
	return 0;
}