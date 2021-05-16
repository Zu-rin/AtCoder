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
	int a, b;
} edge;

void FindParent(vector<vector<int>> &d, vector<int> &p, int n = 1) {
	for (int nx : d[n]) {
		if (p[nx])
			continue;
		p[nx] = n;
		FindParent(d, p, nx);
	}
	return;
}

void Search(vector<vector<int>> &d, vector<ll>& ans) {
	vector<int> ok(ans.size(), 1);
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int n = que.front();
		que.pop();
		ok[n] = 0;
		for (int nx : d[n]) {
			if (ok[nx]) {
				que.push(nx);
				ans[nx] += ans[n];
			}
		}
	}
	return;
}

int main(void) {
	int num, i, j, t, a, b, q;
	ll x;
	cin >> num;
	vector<vector<int>> d(num + 1);
	vector<int> p(num + 1, 0);
	vector<ll> ans(num + 1, 0);
	vector<edge> e(num - 1);
	p[1] = 1;
	rep(i, num - 1) {
		cin >> a >> b;
		e[i] = { a, b };
		d[a].push_back(b);
		d[b].push_back(a);
	}
	FindParent(d, p);
	cin >> q;
	rep(i, q) {
		cin >> t >> j >> x;
		edge& ed = e[j - 1];
		if (t == 1) {
			int tag = (p[ed.a] == ed.b ? ed.a : 1);
			ans[tag] += x;
			if (tag == 1)
				ans[ed.b] -= x;
		}
		else {
			int tag = (p[ed.b] == ed.a ? ed.b : 1);
			ans[tag] += x;
			if (tag == 1)
				ans[ed.a] -= x;
		}
	}
	Search(d, ans);
	for (i = 1; i <= num; i++)
		cout << ans[i] << "\n";
	return 0;
}