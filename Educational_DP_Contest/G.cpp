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

void TopoSort(const vector<list<int>> & d, vector<int> & in, queue<int> & ans) {
	int i, a;
	queue<int> que;
	rep(i, in.size()) {
		if (!in[i])
			que.push(i);
	}
	while (!que.empty()) {
		a = que.front();
		que.pop();
		ans.push(a);
		for (auto it = d[a].begin(); it != d[a].end(); it++) {
			in[*it]--;
			if (!in[*it])
				que.push(*it);
		}
	}
	return;
}

int main(void) {
	int num, m, i, a, b, ma = 0;
	cin >> num >> m;
	queue<int> topo;
	vector<int> in(num + 1, 0), ans(num + 1, 0);
	vector<list<int>> d(num + 1);
	rep(i, m) {
		cin >> a >> b;
		d[a].push_back(b);
		in[b]++;
	}
	TopoSort(d, in, topo);
	while (!topo.empty()) {
		a = topo.front();
		topo.pop();
		for (auto it = d[a].begin(); it != d[a].end(); it++)
			chmax(ans[*it], ans[a] + 1);
		chmax(ma, ans[a]);
	}
	cout << ma << "\n";
	return 0;
}