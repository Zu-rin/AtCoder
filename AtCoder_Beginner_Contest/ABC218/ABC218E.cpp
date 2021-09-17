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

class UnionFind {
private:
	vector<int> p;

public:
	UnionFind(int num) {
		p.resize(num + 1);
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
		return;
	}

	int Same(int a, int b) {
		a = Parent(a);
		b = Parent(b);
		return a == b;
	}
};

struct Edge {
	int a = 0, b = 0, c = 0;
	Edge() {
		scanf("%d%d%d", &a, &b, &c);
	}
	bool operator<(const Edge& r) {
		return c < r.c;
	}
};

ll kruskal(int num, vector<Edge>& e) {
	ll ans = 0;
	UnionFind uf(num + 1);
	for (Edge& ed : e) {
		if (!uf.Same(ed.a, ed.b))
			uf.Union(ed.a, ed.b);
		else if (ed.c > 0)
			ans += ed.c;
	}
	return ans;
}

int main(void) {
	int num, m, i, a, b, c;
	cin >> num >> m;
	vector<Edge> e(m);
	sort(e.begin(), e.end());
	cout << kruskal(num, e) << "\n";
	return 0;
}