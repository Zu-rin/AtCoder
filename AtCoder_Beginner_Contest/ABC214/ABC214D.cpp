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

typedef struct Edge {
	int u, v, c;
	void input() {
		cin >> u >> v >> c;
	}
	friend bool operator<(const Edge& l, const Edge& r) {
		return l.c < r.c;
	}
} edge;

class UnionFind {
private:
	vector<int> p;
	vector<ll> n;

public:
	UnionFind(int num) {
		p.resize(num + 1);
		n.resize(num + 1);
		fill(n.begin(), n.end(), 1);
		for (int i = 0; i < p.size(); i++)
			p[i] = i;
	}

	int Parent(int n) {
		if (p[n] == n)
			return n;
		return p[n] = Parent(p[n]);
	}

	void Union(int a, int b) {
		a = Parent(a);
		b = Parent(b);
		p[a] = b;
		n[b] += n[a];
		return;
	}

	int Same(int a, int b) {
		a = Parent(a);
		b = Parent(b);
		return a == b;
	}

	ll Size(int a) {
		return n[Parent(a)];
	}
};

int main(void) {
	int num, i;
	ll ans = 0;
	cin >> num;
	vector<edge> e(num - 1);
	UnionFind uf(num + 1);
	rep(i, e.size())
		e[i].input();
	sort(e.begin(), e.end());
	rep(i, e.size()) {
		ans += uf.Size(e[i].u) * uf.Size(e[i].v) * e[i].c;
		uf.Union(e[i].u, e[i].v);
	}
	cout << ans << "\n";
	return 0;
}