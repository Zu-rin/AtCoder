#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
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

ll x, y;

ll Solve(ll n, map<ll, ll> & dp) {
	if (dp.count(n))
		return dp[n];
	ll ans = abs(x - n);
	if (n & 1) {
		chmin(ans, Solve((n - 1) / 2, dp) + 2);
		chmin(ans, Solve((n + 1) / 2, dp) + 2);
	}
	else {
		chmin(ans, Solve(n >> 1, dp) + 1);
	}
	return dp[n] = ans;
}

int main(void) {
	map<ll, ll> dp;
	cin >> x >> y;
	dp[1] = x - 1;
	cout << Solve(y, dp) << "\n";
	return 0;
}