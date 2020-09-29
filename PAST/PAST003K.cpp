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

int main(void) {
	int num, q, i, s, g, a, buf;
	cin >> num >> q;
	vector<pp> d(num + 1);
	vector<int> p(num + 1, 0), ans(num + 1);
	rep(i, d.size())
		d[i].first = d[i].second = i;
	rep(i, q) {
		cin >> s >> g >> a;
		buf = p[a];
		p[a] = d[g].second;
		if (p[a] == 0)
			d[g].first = 0;
		d[g].second = d[s].second;
		d[s].second = buf;
		if (buf == 0)
			d[s].first = 0;
	}
	for (i = 1; i <= num; i++) {
		a = d[i].second;
		while (a != 0) {
			ans[a] = i;
			a = p[a];
		}
	}
	for (i = 1; i <= num; i++)
		cout << ans[i] << "\n";
	return 0;
}