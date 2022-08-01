#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
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

struct circle {
	ll x, y, r = 0;
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

int isCross(circle& a, circle& b) {
	ll d = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	if (d > (a.r + b.r) * (a.r + b.r))
		return false;
	if (d < (a.r - b.r) * (a.r - b.r))
		return false;
	return true;
}

int main(void) {
	int num, i, j, s, e;
	circle a, b;
	cin >> num >> a.x >> a.y >> b.x >> b.y;
	UnionFind uf(num);
	vector<circle> d(num);
	rep(i, num)
		cin >> d[i].x >> d[i].y >> d[i].r;
	rep(i, num) {
		rep(j, i) {
			if (uf.Same(i, j))
				continue;
			if (isCross(d[i], d[j]))
				uf.Union(i, j);
		}
	}
	rep(i, num) {
		if (isCross(a, d[i])) {
			s = i;
			break;
		}
	}
	rep(i, num) {
		if (isCross(b, d[i])) {
			e = i;
			break;
		}
	}
	if (uf.Same(s, e))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}