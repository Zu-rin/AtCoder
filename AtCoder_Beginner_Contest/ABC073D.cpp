#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1 << 28
using namespace std;

int Search(vector<int> &a, vector<int> &r, int c, int n, const vector<vector<int>> &d) {
	int i, ans = INF;
	if (n == a.size()) {
		ans = 0;
		for (i = 0; i < a.size() - 1; i++)
			ans += d[r[a[i]]][r[a[i + 1]]];
		return ans;
	}
	for (i = 0; i < a.size(); i++) {
		if ((c >> i) & 1) {
			a[n] = i;
			ans = min(ans, Search(a, r, c - (1 << i), n + 1, d));
		}
	}
	return ans;
}

int main(void) {
	int num, m, r, i, j, k, a, b, c, ans;
	cin >> num >> m >> r;
	vector<vector<int>> d(num + 1, vector<int>(num + 1, INF));
	vector<int> x(r), R(r);
	for (i = 1; i <= num; i++)
		d[i][i] = 0;
	for (i = 0; i < r; i++)
		scanf_s("%d", &R[i]);
	for (i = 0; i < m; i++) {
		scanf_s("%d%d%d", &a, &b, &c);
		d[a][b] = min(d[a][b], c);
		d[b][a] = min(d[b][a], c);
	}
	for (k = 1; k <= num; k++) {
		for (i = 1; i <= num; i++) {
			for (j = 1; j <= num; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	ans = Search(x, R, (1 << r) - 1, 0, d);
	cout << ans << "\n";
	return 0;
}