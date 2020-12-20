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

queue<int> que;
void Search(int n, vector<list<int>>& d, vector<int>& ans) {
	for (auto it = d[n].begin(); it != d[n].end(); it++) {
		if (ans[*it] == INF) {
			ans[*it] = n + 1;
			que.push(*it);
		}
	}
	if (!que.empty()) {
		n = que.front();
		que.pop();
		Search(n, d, ans);
	}
	return;
}

int main(void) {
	int n, m, i, a, b;
	cin >> n >> m;
	vector<list<int>> d(n);
	vector<int> ans(n, INF);
	ans[0] = 0;
	rep(i, m) {
		cin >> a >> b;
		a--; b--;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	Search(0, d, ans);
	printf("Yes\n");
	for (i = 1; i < n; i++)
		cout << ans[i] << "\n";
	return 0;
}