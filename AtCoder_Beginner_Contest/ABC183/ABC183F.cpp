#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
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

void Marge(map<int, int>& a, map<int, int>& b) {
	for (auto it : a) {
		b[it.first] += it.second;
	}
	return;
}

int main(void) {
	int num, q, i, a, x, y;
	cin >> num >> q;
	vector<map<int, int>> s(num + 1);
	UnionFind uf(num);
	for (int i = 1; i <= num; i++) {
		cin >> a;
		s[i][a] = 1;
	}
	rep(i, q) {
		cin >> a >> x >> y;
		if (a == 1 && !uf.Same(x, y)) {
			if (s[uf.Parent(x)].size() <= s[uf.Parent(y)].size()) {
				Marge(s[uf.Parent(x)], s[uf.Parent(y)]);
				uf.Union(x, y);
			}
			else {
				Marge(s[uf.Parent(y)], s[uf.Parent(x)]);
				uf.Union(y, x);
			}
		}
		else if (a == 2) {
			if (!s[uf.Parent(x)].count(y))
				printf("0\n");
			else
				cout << s[uf.Parent(x)][y] << "\n";
		}
	}
	return 0;
}