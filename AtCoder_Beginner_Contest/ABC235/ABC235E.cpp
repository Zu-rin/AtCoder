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

struct edge {
	int a, b, c, i;
	friend bool operator<(const edge& l, const edge& r) {
		return l.c < r.c;
	}
};

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

int main(void) {
	int num, i, m, q, a, b, c;
	cin >> num >> m >> q;
	UnionFind uf(num + 1);
	vector<char> ans(q, (char)0);
	vector<edge> d;
	rep(i, m) {
		cin >> a >> b >> c;
		d.push_back(edge{ a, b, c, -1 });
	}
	rep(i, q) {
		cin >> a >> b >> c;
		d.push_back(edge{ a, b, c, i });
	}
	sort(d.begin(), d.end());
	for (edge& e : d) {
		if (uf.Same(e.a, e.b))
			continue;
		if (e.i != -1)
			ans[e.i] = 1;
		else
			uf.Union(e.a, e.b);
	}
	for (char ok : ans) {
		if (ok)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}