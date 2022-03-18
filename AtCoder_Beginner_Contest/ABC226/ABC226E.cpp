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
		p[b] = a;
		return;
	}

	int Same(int a, int b) {
		a = Parent(a);
		b = Parent(b);
		return a == b;
	}
};

ll Pow(ll n, ll k) {
	ll ans = 1, a = n % MOD;
	while (k > 0) {
		if (k & 1) {
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		k >>= 1;
	}
	return ans;
}

int main(void) {
	int num, m, i, a, b, k = 0, x = 0;
	cin >> num >> m;
	vector<char> ng(num + 1, 1), r(num + 1, 0);
	UnionFind uf(num + 1);
	rep(i, m) {
		cin >> a >> b;
		if (uf.Same(a, b)) {
			if (r[uf.Parent(a)]) {
				x = 1;
				break;
			}
			k++;
			r[uf.Parent(a)] = 1;
		}
		int mi = min(a, b), ma = max(a, b);
		r[uf.Parent(mi)] += r[uf.Parent(ma)];
		uf.Union(mi, ma);
		ng[a] = ng[b] = 0;
	}
	for (int i = 1; i <= num; i++) {
		if (ng[i]) {
			x = 1;
			break;
		}
	}
	if (num != m or x)
		printf("0\n");
	else
		cout << Pow(2ll, k) << "\n";
	return 0;
}