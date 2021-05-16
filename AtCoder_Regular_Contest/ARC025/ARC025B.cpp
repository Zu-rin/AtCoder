#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j, h, w, a, b, ans = 0;
	cin >> h >> w;
	vector<vector<int>> d(h + 1, vector<int>(w + 1, 0));
	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			cin >> d[i][j];
			if ((i + j) & 1)
				d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] - d[i][j];
			else
				d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
		}
	}
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			for (a = 1; i + a <= h; a++) {
				for (b = 1; j + b <= w; b++) {
					if (d[i + a][j + b] + d[i][j] - d[i + a][j] - d[i][j + b] == 0)
						ans = max(ans, a * b);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}