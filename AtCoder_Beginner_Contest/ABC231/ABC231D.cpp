#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 998244353
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

int main(void) {
	int num, m, i, j, a, b;
	cin >> num >> m;
	vector<int> ok(num + 1, 1);
	vector<vector<int>> d(num + 1);
	UnionFind uf(num + 1);
	rep(i, m) {
		cin >> a >> b;
		if (d[a].size() == 2 || d[b].size() == 2 || uf.Same(a, b)) {
			printf("No\n");
			return 0;
		}
		d[a].push_back(b);
		d[b].push_back(a);
		uf.Union(a, b);
	}
	printf("Yes\n");
	return 0;
}