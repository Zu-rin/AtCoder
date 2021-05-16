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
#define INF 1 << 27

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, j, k, m, a, b, c;
	ll ans = 0;
	cin >> num >> m;
	vector<vector<int>> d(num + 1, vector<int>(num + 1, INF));
	rep(i, num + 1)
		d[i][i] = 0;
	rep(i, m) {
		cin >> a >> b >> c;
		d[a][b] = chmin(d[b][a], c);
	}
	for (k = 1; k <= num; k++) {
		for (i = 1; i < num; i++) {
			for (j = i + 1; j <= num; j++) {
				d[j][i] = chmin(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (i = 1; i < num; i++) {
		for (j = i + 1; j <= num; j++) {
			ans += d[i][j];
		}
	}
	cin >> m;
	rep(k, m) {
		cin >> a >> b >> c;
		ans -= max(0, d[a][b] - c);
		d[a][b] = chmin(d[b][a], c);
		for (i = 1; i < num; i++) {
			for (j = i + 1; j <= num; j++) {
				int x = min(d[i][a] + d[b][j], d[i][b] + d[a][j]) + c;
				if (x < d[i][j]) {
					ans -= d[i][j] - x;
					d[i][j] = d[j][i] = x;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}