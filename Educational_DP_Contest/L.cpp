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

ll Search(vector<vector<ll>> & dp, vector<vector<char>> & ok, const vector<ll> & d, int l, int r, char p = 0) {
	if (l > r)
		return 0;
	if (ok[l][r])
		return dp[l][r];
	ll a, b;
	a = Search(dp, ok, d, l + 1, r, !p);
	b = Search(dp, ok, d, l, r - 1, !p);
	ok[l][r] = 1;
	return dp[l][r] = p ? min(a - d[l], b - d[r]) : max(a + d[l], b + d[r]);
}

int main(void) {
	int num, i;
	ll ans;
	cin >> num;
	vector<ll> d(num);
	vector<vector<char>> ok(num, vector<char>(num, 0));
	vector<vector<ll>> dp(num, vector<ll>(num, 0));
	rep(i, num)
		cin >> d[i];
	ans = Search(dp, ok, d, 0, num - 1);
	cout << ans << "\n";
	return 0;
}