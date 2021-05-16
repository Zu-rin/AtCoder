#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

queue<int> que;

void Search(int n, vector<vector<int>> &mp, vector<int> &ok, vector<int> &len) {
	ok[n] = false;
	for (int i = 1; i < mp[n].size(); i++) {
		if (ok[i] && mp[n][i]) {
			ok[i] = false;
			len[i] = len[n] + 1;
			que.push(i);
		}
	}
	if (!que.empty()) {
		n = que.front();
		que.pop();
		Search(n, mp, ok, len);
	}
	return;
}

void Change(vector<vector<int>> &mp, vector<int> &len) {
	int i, j;
	for (i = 1; i < mp.size(); i++) {
		for (j = 1; j < mp[i].size(); j++) {
			if (mp[i][j] && len[i] + 1 != len[j]) {
				mp[i][j] = false;
			}
		}
	}
	return;
}

ll Search(int n, vector<vector<int>> &mp, vector<ll> &dp) {
	if (dp[n] > 0)
		return dp[n];
	for (int i = 1; i < mp[n].size(); i++) {
		if (mp[n][i]) {
			dp[n] += Search(i, mp, dp);
			dp[n] %= MOD;
		}
	}
	return dp[n];
}

int main(void) {
	int num, i, s, g, m, a, b;
	ll ans;
	cin >> num >> s >> g >> m;
	vector<vector<int>> mp(num + 1, vector<int>(num + 1, false));
	vector<int> ok(num + 1, true), len(num + 1, 1);
	vector<ll> dp(num + 1, 0);
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		mp[a][b] = true;
		mp[b][a] = true;
	}
	ok[s] = false;
	Search(s, mp, ok, len);
	Change(mp, len);
	dp[g] = 1;
	ans = Search(s, mp, dp);
	cout << ans << "\n";
	return 0;
}