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
	int num, m, i, j, k, ans;
	cin >> num >> m;
	ans = num;
	vector<vector<int>> d(num, vector<int>(m));
	vector<int> p(num, 0), ok(m + 1, 1);
	rep(i, num) {
		rep(j, m)
			cin >> d[i][j];
	}
	rep(k, m - 1) {
		int s, ma = 0;
		vector<int> a(m + 1, 0);
		rep(i, num) {
			if (ma < ++a[d[i][p[i]]]) {
				ma = a[d[i][p[i]]];
				s = d[i][p[i]];
			}
		}
		chmin(ans, ma);
		ok[s] = 0;
		rep(i, num) {
			while (!ok[d[i][p[i]]])
				p[i]++;
		}
	}
	cout << ans << "\n";
	return 0;
}