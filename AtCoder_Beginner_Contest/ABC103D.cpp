#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int i, n, m, a = 0, ans = 0;
	cin >> n >> m;
	vector<pair<int, int>> d(m);
	for (i = 0; i < m; i++)
		scanf_s("%d%d", &d[i].second, &d[i].first);
	sort(d.begin(), d.end());
	for (i = 0; i < m; i++) {
		if (a < d[i].second) {
			ans++;
			a = d[i].first - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}