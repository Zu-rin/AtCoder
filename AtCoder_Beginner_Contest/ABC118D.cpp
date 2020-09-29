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
	int x, num, i, j, v[10] = { 0,2,5,5,4,5,6,3,7,6 };
	cin >> x >> num;
	string ans = "";
	vector<int> d(num), dp(x + 1, -INF);
	rep(i, num)
		cin >> d[i];
	dp[0] = 0;
	rep(i, dp.size()) {
		if (dp[i] != -INF) {
			rep(j, num) {
				if(i + v[d[j]] <= x)
					chmax(dp[i + v[d[j]]], dp[i] + 1);
			}
		}
	}
	sort(d.begin(), d.end(), greater<int>());
	for (i = x; i > 0;) {
		rep(j, num) {
			if (v[d[j]] <= i && dp[i - v[d[j]]] == dp[i] - 1) {
				ans += '0' + d[j];
				i -= v[d[j]];
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}