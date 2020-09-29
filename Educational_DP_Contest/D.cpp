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
	int num, i, W;
	ll v, w;
	cin >> num >> W;
	vector<ll> dp(W + 1, 0);
	rep(i, num) {
		cin >> w >> v;
		for (int j = W - w; j >= 0; j--)
			chmax(dp[j + w], dp[j] + v);
	}
	cout << dp[W] << "\n";
	return 0;
}