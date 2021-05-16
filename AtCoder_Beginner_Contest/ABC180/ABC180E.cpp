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

typedef struct {
	int x, y, z;
} node;

int Cost(node& a, node& b) {
	return abs(b.x - a.x) + abs(b.y - a.y) + max(0, b.z - a.z);
}

int Search(int n, int k, vector<node>& d, vector<vector<int>>& dp) {
	if (dp[n][k] != INF)
		return dp[n][k];
	if (k == (1 << d.size()) - 1)
		return dp[n][k] = Cost(d[n], d[0]);
	int i, ans = INF;
	rep(i, d.size()) {
		if ((1 << i) & k)
			continue;
		chmin(ans, Search(i, k + (1 << i), d, dp) + Cost(d[n], d[i]));
	}
	return dp[n][k] = ans;
}

int main(void) {
	int num, i;
	cin >> num;
	vector<node> d(num);
	vector<vector<int>> dp(num, vector<int>(1 << num, INF));
	rep(i, num) {
		cin >> d[i].x >> d[i].y >> d[i].z;
	}
	cout << Search(0, 1, d, dp) << "\n";
	return 0;
}