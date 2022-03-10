#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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

int main(void) {
	int num, i, m, a, b;
	cin >> num >> m;
	vector<int> ans(num + 1);
	vector<vector<int>> d(num + 1);
	UnionFind uf(num);
	rep(i, m) {
		cin >> a >> b;
		d[a].push_back(b);
	}
	for (i = num; i > 1; i--) {
		set<int> st;
		for (int a : d[i])
			st.insert(uf.Parent(a));
		ans[i - 1] = ans[i] - st.size() + 1;
		for (int a : d[i])
			uf.Union(i, a);
	}
	for (i = 1; i <= num; i++)
		cout << ans[i] << "\n";
	return 0;
}