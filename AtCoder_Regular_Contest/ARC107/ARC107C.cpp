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
	vector<int> p, n;

public:
	UnionFind(int num) {
		p.resize(num + 1);
		n.resize(num + 1);
		fill(n.begin(), n.end(), 1);
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
		if (a == b)
			return;
		p[a] = b;
		n[b] += n[a];
		return;
	}

	int Same(int a, int b) {
		return Parent(a) == Parent(b);
	}

	int Size(int a) {
		return n[Parent(a)];
	}
};

// d[n] = n! ‚Ì”z—ñ‰Šú‰»
void Ini_fact(vector<ll>& d) {
	d[1] = 1;
	for (ll i = 2; i < d.size(); i++)
		d[i] = d[i - 1] * i % MOD;
	return;
}

int main(void) {
	int num, k, i, j, s, t;
	ll ans = 1, a = 0, b = 0;
	cin >> num >> k;
	vector<ll> kai(num + 10);
	vector<vector<int>> d(num, vector<int>(num));
	UnionFind x(num), y(num);
	Ini_fact(kai);
	rep(i, num) {
		rep(j, num)
			cin >> d[i][j];
	}
	rep(s, num) {
		for (t = s + 1; t < num; t++) {
			int ok1 = 1, ok2 = 1;
			rep(i, num) {
				if (d[s][i] + d[t][i] > k) {
					ok1 = 0;
				}
				if (d[i][s] + d[i][t] > k) {
					ok2 = 0;
				}
			}
			if (ok1)
				x.Union(s, t);
			if (ok2)
				y.Union(s, t);
		}
	}
	rep(i, num) {
		if (i == x.Parent(i)) {
			ans *= kai[x.Size(i)];
		}
		if (i == y.Parent(i)) {
			ans *= kai[y.Size(i)];
		}
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}