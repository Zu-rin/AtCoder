#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, c, i, j, k, l, aa, bb, cc, ans = 1e9;
	cin >> num >> c;
	vector<vector<int>> cost(c, vector<int>(c)), d(3, vector<int>(c, 0));
	for (i = 0; i < c; i++) {
		for (j = 0; j < c; j++) {
			scanf_s("%d", &cost[i][j]);
		}
	}
	for (i = 1; i <= num; i++) {
		for (j = 1; j <= num; j++) {
			scanf_s("%d", &aa);
			d[(i + j) % 3][aa - 1]++;
		}
	}
	for (i = 0; i < c; i++) {
		for (aa = 0, l = 0; l < c; l++)
			aa += d[0][l] * cost[l][i];
		for (j = 0; j < c; j++) {
			if (i == j)
				continue;
			for (bb = 0, l = 0; l < c; l++)
				bb += d[1][l] * cost[l][j];
			for (k = 0; k < c; k++) {
				if (i != k && j != k) {
					for (cc = 0, l = 0; l < c; l++)
						cc += d[2][l] * cost[l][k];
					ans = min(ans, aa + bb + cc);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}