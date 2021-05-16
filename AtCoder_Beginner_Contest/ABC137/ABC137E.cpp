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
	int from, to, cost;
} edge;

int Update(vector<int>& ans, vector<edge>& d) {
	int i, update = 0;
	rep(i, d.size()) {
		edge& e = d[i];
		if (ans[e.from] != -INF && ans[e.to] < ans[e.from] + e.cost) {
			update = 1;
			ans[e.to] = ans[e.from] + e.cost;
		}
	}
	return update;
}

void DFS(int n, vector<list<int>>& d, vector<int>& ng) {
	ng[n] = 0;
	for (auto it = d[n].begin(); it != d[n].end(); it++) {
		if (ng[*it])
			DFS(*it, d, ng);
	}
	return;
}

void Erase(vector<edge>& d, vector<int>& ng) {
	for (int i = d.size() - 1; i >= 0; i--) {
		if (ng[d[i].from] || ng[d[i].to])
			d.erase(d.begin() + i);
	}
	return;
}

void Optim(int num, vector<edge> &d) {
	int i;
	vector<list<int>> a(num + 1), b(num + 1);
	rep(i, d.size()) {
		edge& e = d[i];
		a[e.from].push_back(e.to);
		b[e.to].push_back(e.from);
	}
	vector<int> ng(num + 1, 1);
	DFS(1, a, ng);
	Erase(d, ng);
	fill(ng.begin(), ng.end(), 1);
	DFS(num, b, ng);
	Erase(d, ng);
}

int main(void) {
	int num, m, i, p;
	cin >> num >> m >> p;
	vector<int> ans(num + 1, -INF);
	vector<edge> d(m);
	rep(i, m) {
		cin >> d[i].from >> d[i].to >> d[i].cost;
		d[i].cost -= p;
	}
	ans[1] = 0;
	Optim(num, d);
	rep(i, num)
		Update(ans, d);
	if (Update(ans, d))
		printf("-1\n");
	else if (ans[num] <= 0)
		printf("0\n");
	else
		cout << ans[num] << "\n";
	return 0;
}