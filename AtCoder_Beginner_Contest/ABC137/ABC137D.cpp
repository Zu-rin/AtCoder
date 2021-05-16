#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, m, a, b, i, j = 0;
	ll ans = 0;
	cin >> num >> m;
	vector<pair<int, int>> d(num);
	priority_queue<int> que;
	for (i = 0; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		d[i] = make_pair(a, b);
	}
	sort(d.begin(), d.end());
	j = 0;
	for (i = 1; i <= m; i++) {
		while (j < num && d[j].first == i) {
			que.push(d[j].second);
			j++;
		}
		if (!que.empty()) {
			ans += que.top();
			que.pop();
		}
	}
	cout << ans << "\n";
	return 0;
}