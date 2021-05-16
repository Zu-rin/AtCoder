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

bool Judge(int n, int p) {
	int a = 0;
	while (n > 0) {
		if (n & 1)
			a++;
		n >>= 1;
	}
	return a == p;
}

int Solve(vector<vector<pp>> &d, int v, int num, int q) {
	int i, j, ans = 0;
	vector<int> a(num, 0);
	rep(i, d.size()) {
		if ((1 << i) & v) {
			rep(j, d[i].size()) {
				pp& e = d[i][j];
				a[e.first] += e.second;
			}
		}
	}
	sort(a.begin(), a.end(), greater<int>());
	rep(i, q)
		ans += a[i];
	return ans;
}

int main(void) {
	int n, m, p, q, k, i, a, b, c, ans = 0;
	cin >> n >> m >> p >> q >> k;
	vector<vector<pp>> d(n);
	rep(i, k) {
		cin >> a >> b >> c;
		d[a - 1].push_back(pp(b - 1, c));
	}
	rep(i, 1 << n) {
		if (Judge(i, p)) {
			chmax(ans, Solve(d, i, m, q));
		}
	}
	cout << ans << "\n";
	return 0;
}