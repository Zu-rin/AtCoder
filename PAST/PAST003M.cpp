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
void Search(int n, vector<list<int>> & e, vector<int> & ans) {
	for (auto it = e[n].begin(); it != e[n].end(); it++) {
		if (ans[*it] == INF) {
			ans[*it] = ans[n] + 1;
			que.push(*it);
		}
	}
	if (!que.empty()) {
		n = que.front();
		que.pop();
		Search(n, e, ans);
	}
	return;
}

int Mpass(int v, vector<vector<)

int main(void) {
	int num, m, k, i, a, b, s;
	cin >> num >> m;
	vector<list<int>> edge(num + 1);
	rep(i, m) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	cin >> s >> k;
	vector<int> tag(k);
	vector<vector<int>> d(k, vector<int>(num + 1, INF));
	vector<int> st(num + 1, INF);
	rep(i, k)
		cin >> tag[i];
	Search(s, edge, st);
	rep(i, k)
		Search(tag[i], edge, d[i]);


	return 0;
}