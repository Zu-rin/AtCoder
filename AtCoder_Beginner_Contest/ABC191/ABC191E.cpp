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
#define INF 1 << 29

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

void Dijk(int s, vector<vector<pp>> &d, vector<int> &ans) {
	priority_queue<pp, vector<pp>, greater<pp>> que;
	que.push({ 0, s });
	while (!que.empty()) {
		int c = que.top().first, n = que.top().second;
		que.pop();
		if (ans[n] == INF) {
			ans[n] = c;
			for (pp& p : d[n]) {
				if (ans[p.second] == INF) {
					que.push(pp(p.first + c, p.second));
				}
			}
		}
	}
}

int main(void) {
	int num, m, i, a, b, c;
	cin >> num >> m;
	vector<vector<pp>> d(num + 1);
	vector<vector<int>> ans(num + 1, vector<int>(num + 1, INF));
	vector<int> k(num + 1, INF);
	rep(i, m) {
		cin >> a >> b >> c;
		d[a].push_back(pp(c, b));
		if (a == b)
			chmin(k[a], c);
	}
	for (i = 1; i <= num; i++) {
		Dijk(i, d, ans[i]);
	}
	for (i = 1; i <= num; i++) {
		a = INF;
		for (int j = 1; j <= num; j++) {
			if (i == j)
				chmin(a, k[i]);
			else
				chmin(a, ans[i][j] + ans[j][i]);
		}
		if (a != INF)
			cout << a << "\n";
		else
			printf("-1\n");
	}
	return 0;
}