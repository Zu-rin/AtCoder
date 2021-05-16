#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, a, b, ans = 0;
	cin >> num;
	vector<int> ok(num, false);
	vector<pair<int, int>> x(num), y(num);	//pos, id
	vector<list<pair<int, int>>> mp(num);	//cost, to
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	pair<int, int> p;
	for (i = 0; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		x[i] = make_pair(a, i);
		y[i] = make_pair(b, i);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for (i = 0; i < num - 1; i++) {
		mp[x[i].second].push_back(make_pair(x[i + 1].first - x[i].first, x[i + 1].second));
		mp[x[i + 1].second].push_back(make_pair(x[i + 1].first - x[i].first, x[i].second));
		mp[y[i].second].push_back(make_pair(y[i + 1].first - y[i].first, y[i + 1].second));
		mp[y[i + 1].second].push_back(make_pair(y[i + 1].first - y[i].first, y[i].second));
	}
	for (auto itr = mp[0].begin(); itr != mp[0].end(); itr++)
		que.push(*itr);
	ok[0] = true;
	while (!que.empty()) {
		a = que.top().second;
		if (ok[a])
			que.pop();
		else {
			ok[a] = true;
			ans += que.top().first;
			que.pop();
			for (auto itr = mp[a].begin(); itr != mp[a].end(); itr++)
				que.push(*itr);
		}
	}
	printf("%d\n", ans);
	return 0;
}