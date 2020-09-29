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
	int num, i, j, ans;
	cin >> num;
	vector<int> d(num);
	vector<pp> dp(num, pp(0, 0));
	rep(i, num)
		cin >> d[i];
	for (i = 1; i < num; i++) {
		rep(j, i) {
			if (d[j] < d[i])
				chmax(dp[i].second, dp[j].first + 1);
			else if (d[j] > d[i])
				chmax(dp[i].first, dp[j].second + 1);
		}
	}
	ans = 1 + max(dp[num - 1].first, dp[num - 1].second);
	if (ans < 3)
		printf("0\n");
	else
		cout << ans << "\n";
	return 0;
}