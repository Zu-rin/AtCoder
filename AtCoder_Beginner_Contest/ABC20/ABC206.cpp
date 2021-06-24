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
	int num, i, ans = 0;
	cin >> num;
	vector<int> d(num);
	set<int> st;
	UnionFind uf(200001);
	rep(i, num)
		cin >> d[i];
	rep(i, num / 2) {
		uf.Union(d[i], d[num - i - 1]);
		st.insert(d[i]);
		st.insert(d[num - i - 1]);
	}
	for (auto x : st) {
		if (x != uf.Parent(x))
			ans++;
	}
	cout << ans << "\n";
	return 0;
}