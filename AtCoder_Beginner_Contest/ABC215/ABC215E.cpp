#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 998244353
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, j, v;
	ll ans = 0;
	string s;
	cin >> num >> s;
	ll dp[1024][10] = { 0 };
	rep(i, num)
		s[i] -= 'A';
	rep(i, num) {
		for(int v = 1023; v > 0; v--) {
			if (v & (1 << s[i])) {
				dp[v][s[i]] <<= 1;
				if (v == (1 << s[i]))
					dp[v][s[i]]++;
				dp[v][s[i]] %= MOD;
			}
			else {
				int vv = v | (1 << s[i]);
				rep(j, 10)
					dp[vv][s[i]] += dp[v][j];
				dp[vv][s[i]] %= MOD;
			}
		}
	}
	for(i = 1; i < 1024; i++) {
		rep(j, 10) {
			ans += dp[i][j];
			ans %= MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}