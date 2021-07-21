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
#define INF 1 << 29

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

struct Edge {
	int to;
	ll cost;
};

int main(void) {
	int num, m, i, j, k, a, b, c;
	ll ans = 0;
	cin >> num >> m;
	vector<vector<int>> d(num, vector<int>(num, INF));
	rep(i, m) {
		cin >> a >> b >> c;
		d[a - 1][b - 1] = c;
	}
	rep(i, num)
		d[i][i] = 0;
	rep(k, num) {
		rep(i, num) {
			rep(j, num) {
				chmin(d[i][j], d[i][k] + d[k][j]);
				ans += (d[i][j] == INF ? 0 : d[i][j]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}