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
	int num, m, i, j, a, b;
	cin >> num >> m;
	vector<int> d(num, 0);
	vector<int> dp(1 << num, INF);
	rep(i, num)
		d[i] = 1 << i;
	rep(i, m) {
		cin >> a >> b;
		a--;
		b--;
		d[a] |= 1 << b;
		d[b] |= 1 << a;
	}
	dp[0] = 1;
	rep(i, 1 << num) {
		rep(j, num) {
			if (dp[i] == 1 && (i & d[j]) == i)
				dp[i | (1 << j)] = 1;
		}
	}
	for (i = 3; i < (1 << num); i++) {
		for (j = i; --j &= i;) {
			chmin(dp[i], dp[j] + dp[i ^ j]);
		}
	}
	cout << dp[dp.size() - 1] << "\n";
	return 0;
}