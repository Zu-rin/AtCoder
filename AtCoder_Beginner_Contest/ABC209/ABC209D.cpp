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

void BFS(vector<vector<int>> &d, vector<int> &ans) {
	queue<pp> que;
	que.push(pp(1, 0));
	while (!que.empty()) {
		int n = que.front().first;
		int c = que.front().second;
		que.pop();
		if (ans[n] == INF) {
			ans[n] = c;
			for (int nx : d[n])
				que.push(pp(nx, c + 1));
		}
	}
}

int main(void) {
	int num, q, i, a, b;
	cin >> num >> q;
	vector<vector<int>> d(num + 1);
	vector<int> x(num + 1, INF);
	rep(i, num - 1) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	BFS(d, x);
	rep(i, q) {
		cin >> a >> b;
		cout << ((x[a] + x[b]) & 1 ? "Road" : "Town") << "\n";
	}
	return 0;
}