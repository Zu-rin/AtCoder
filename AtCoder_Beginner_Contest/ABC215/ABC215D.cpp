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

int num, m;

void Eratos(vector<int> &ans) {
	int i, j, x;
	vector<char> p(100001, 1), d(100001, 0);
	rep(i, num) {
		cin >> x;
		d[x] = 1;
	}
	p[0] = p[1] = 0;
	for (i = 2; i < p.size(); i++) {
		if (p[i]) {
			char ok = 0;
			if (d[i])
				ok = 1;
			for (j = i << 1; j < p.size(); j += i) {
				if (d[j])
					ok = 1;
				p[j] = 0;
			}
			if (ok)
				ans.push_back(i);
		}
	}
	return;
}

int main(void) {
	int i;
	cin >> num >> m;
	vector<int> d(num), p, a(m + 1, 1), ans;
	Eratos(p);
	for(int x : p) {
		for (i = x; i < a.size(); i += x)
			a[i] = 0;
	}
	for(i = 1; i <= m; i++) {
		if (a[i])
			ans.push_back(i);
	}
	cout << ans.size() << "\n";
	rep(i, ans.size())
		cout << ans[i] << "\n";
	return 0;
}