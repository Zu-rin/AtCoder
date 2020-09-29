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
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, W, lim;
	ll v, w;
	cin >> num >> W;
	vector<ll> dp(num * 1000 + 1, INF);
	lim = dp[0] = 0;
	rep(i, num) {
		cin >> w >> v;
		for (int j = lim; j >= 0; j--)
			chmin(dp[j + v], dp[j] + w);
		lim += v;
	}
	for (i = dp.size() - 1; i >= 0; i--) {
		if (dp[i] <= W)
			break;
	}
	cout << i << "\n";
	return 0;
}