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
	int num, i, j;
	string s;
	cin >> num >> s;
	vector<string> d(num);
	vector<ll> dp(s.size() + 1, 0);
	dp[0] = 1;
	rep(i, num)
		cin >> d[i];
	rep(i, s.size()) {
		rep(j, num) {
			if (s.substr(i, d[j].size()) == d[j]) {
				dp[i + d[j].size()] += dp[i];
				dp[i + d[j].size()] %= MOD;
			}
		}
	}
	cout << dp[s.size()] << "\n";
	return 0;
}