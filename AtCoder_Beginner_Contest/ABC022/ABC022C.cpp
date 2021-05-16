#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1 << 28

using namespace std;

int main(void) {
	int House, Road, k, i = 0, j, h1, h2, c, ans = MAX;
	cin >> House >> Road;
	vector<vector<int>> dist(House, vector<int>(House, MAX));
	for (; i < Road; i++) {
		scanf_s("%d%d%d", &h1, &h2, &c);
		dist[--h1][--h2] = c;
		dist[h2][h1] = c;
	}
	for (k = 1; k < House; k++) {
		for (i = 1; i < House; i++) {
			if (i == k)
				continue;
			for (j = i + 1; j < House; j++)
				dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
	for (i = 1; i < House; i++) {
		h1 = dist[0][i];
		for (j = i + 1; j < House; j++)
			ans = min(ans, h1 + dist[i][j] + dist[j][0]);
	}
	if (ans >= MAX)
		ans = -1;
	cout << ans << "\n";
	return 0;
}