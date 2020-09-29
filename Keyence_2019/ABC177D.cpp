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
	int num;
	vector<int> p, n;

public:
	UnionFind(int Num) {
		num = Num;
		p.resize(num + 1);
		n.resize(num + 1);
		for (int i = 0; i < p.size(); i++) {
			p[i] = i;
			n[i] = 1;
		}
	}

	int Parent(int n) {
		if (p[n] == n)
			return n;
		return p[n] = Parent(p[n]);
	}

	void Union(int a, int b) {
		a = Parent(a);
		b = Parent(b);
		if (a != b) {
			p[a] = b;
			n[b] += n[a];
		}
		return;
	}

	int Same(int a, int b) {
		a = Parent(a);
		b = Parent(b);
		return a == b;
	}

	int Maxnum() {
		int i, ans = 0;
		rep(i, num) {
			chmax(ans, n[i]);
		}
		return ans;
	}
};

int main(void) {
	int num, m, i, a, b;
	cin >> num >> m;
	UnionFind d(num + 1);
	rep(i, m) {
		cin >> a >> b;
		d.Union(a, b);
	}
	cout << d.Maxnum() << "\n";
	return 0;
}