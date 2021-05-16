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

int Search(int s, int p, vector<vector<int>> & d, vector<char> &ok, int& tree) {
	int ans = 1;
	ok[s] = 1;
	for (int n : d[s]) {
		if (ok[n]) {
			if(n != p)
				tree = 0;
		}
		else
			ans += Search(n, s, d, ok, tree);
	}
	return ans;
}

int main(void) {
	int num, i, a, b, ans = 0;
	cin >> num;
	UnionFind uf(400001);
	vector<char> ex(400001, 0), ok(400001, 0);
	vector<vector<int>> d(400001);
	rep(i, num) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
		uf.Union(a, b);
		ex[a] = ex[b] = 1;
	}
	for (i = 1; i <= 400000; i++) {
		if (ex[i] && i == uf.Parent(i)) {
			int tree = 1;
			ans += Search(i, 0, d, ok, tree);
			ans -= tree;
		}
	}
	cout << ans << "\n";
	return 0;
}