#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int h, w, k, i, j, a, b, q;
	cin >> h >> w >> k;
	vector<pair<int, int>> d(h * w + 1);
	vector<int> cost(h * w + 1, 0);
	for (j = 0; j < h; j++) {
		for (i = 0; i < w; i++) {
			scanf_s("%d", &a);
			d[a] = make_pair(i, j);
		}
	}
	for (i = 1 + k, j = 1; i <= h * w; i++, j++)
		cost[i] = cost[j] + abs(d[i].first - d[j].first) + abs(d[i].second - d[j].second);
	cin >> q;
	for (i = 0; i < q; i++) {
		scanf_s("%d%d", &a, &b);
		printf("%d\n", cost[b] - cost[a]);
	}
	return 0;
}