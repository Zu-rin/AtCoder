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

int h, w;

struct Point {
	int x, y;
	
	void input() {
		cin >> y >> x;
		x--;
		y--;
		return;
	}

	int id() {
		return y * w + x;
	}
};

int id(int x, int y) {
	return y * w + x;
}

int main(void) {
	int num, i, q, t;
	cin >> h >> w >> q;
	UnionFind uf(w * h);
	vector<vector<char>> r(h, vector<char>(w, 0));
	rep(i, q) {
		cin >> t;
		if (t == 1) {
			Point a;
			a.input();
			r[a.y][a.x] = 1;
			if (a.x > 0 and r[a.y][a.x - 1])
				uf.Union(a.id(), id(a.x - 1, a.y));
			if (a.x < w - 1 and r[a.y][a.x + 1])
				uf.Union(a.id(), id(a.x + 1, a.y));
			if (a.y > 0 and r[a.y - 1][a.x])
				uf.Union(a.id(), id(a.x, a.y - 1));
			if (a.y < h - 1 and r[a.y + 1][a.x])
				uf.Union(a.id(), id(a.x, a.y + 1));
		}
		else {
			Point a, b;
			a.input();
			b.input();
			if (uf.Same(a.id(), b.id()) and r[a.y][a.x])
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}