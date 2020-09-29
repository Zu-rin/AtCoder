#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int h, w, i, j, k, ans = 0;
	cin >> h >> w;
	vector<vector<int>> c(10, vector<int>(10)), d(h, vector<int>(w));
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			scanf_s("%d", &c[i][j]);
		}
	}
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			scanf_s("%d", &d[i][j]);
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			for (k = 0; k < 10; k++) {
				c[j][k] = min(c[j][k], c[j][i] + c[i][k]);
			}
		}
	}
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (d[i][j] >= 0) {
				ans += c[d[i][j]][1];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}