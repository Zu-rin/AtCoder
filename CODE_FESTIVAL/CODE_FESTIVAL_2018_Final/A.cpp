#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, m, i, a, b, c, j;
	long long ans = 0;
	cin >> n >> m;
	vector<vector<int>> d(n + 1, vector<int>(541, 0));
	for (i = 0; i < m; i++) {
		scanf_s("%d%d%d", &a, &b, &c);
		if (c <= 1540) {
			d[a][c - 1000]++;
			d[b][c - 1000]++;
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 270; j++) {
			ans += d[i][j] * d[i][540 - j];
		}
		ans += d[i][270] * (d[i][270] - 1) / 2;
	}
	cout << ans << "\n";
	return 0;
}