#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1 << 25

using namespace std;

int main(void) {
	int n, m, i, j, k, ans = 0, ok;
	cin >> n >> m;
	vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));
	vector<int> a(m), b(m), c(m);
	for (i = 1; i <= n; i++)
		d[i][i] = 0;
	for (i = 0; i < m; i++) {
		scanf_s("%d%d%d", &a[i], &b[i], &c[i]);
		d[a[i]][b[i]] = c[i];
		d[b[i]][a[i]] = c[i];
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			for (k = 1; k <= n; k++) {
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
	for (i = 0; i < m; i++) {
		ok = true;
		for (j = 1; j <= n; j++) {
			if (abs(d[j][a[i]] - d[j][b[i]]) == c[i]) {
				ok = false;
				break;
			}
		}
		if (ok)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}