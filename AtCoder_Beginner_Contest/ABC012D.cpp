#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 29

using namespace std;
typedef long long ll;

int main(void) {
	int num, m, i, j, k, c, ma, ans = INF;
	cin >> num >> m;
	vector<vector<int>> d(num + 1, vector<int>(num + 1, INF));
	for (i = 0; i < m; i++) {
		cin >> j >> k >> c;
		d[j][k] = d[k][j] = c;
	}
	for (i = 1; i <= num; i++) {
		d[i][i] = 0;
	}
	for (k = 1; k <= num; k++) {
		for (i = 1; i <= num; i++) {
			for (j = 1; j <= num; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (i = 1; i <= num; i++) {
		ma = 0;
		for (j = 1; j <= num; j++) {
			ma = max(ma, d[i][j]);
		}
		ans = min(ans, ma);
	}
	cout << ans << "\n";
	return 0;
}