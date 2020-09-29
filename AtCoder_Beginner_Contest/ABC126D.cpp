#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	int num, i, a, b, c;
	cin >> num;
	vector<list<pair<int, int>>> d(num + 1);
	vector<int> ans(num + 1, -1);
	for (i = 0; i < num - 1; i++) {
		scanf_s("%d%d%d", &a, &b, &c);
		c &= 1;
		d[a].push_back(make_pair(b, c));
		d[b].push_back(make_pair(a, c));
	}
	queue<int> que;
	a = 1;
	ans[1] = 0;
	while (true) {
		c = ans[a];
		for (auto itr = d[a].begin(); itr != d[a].end(); itr++) {
			if (ans[(*itr).first] < 0) {
				que.push((*itr).first);
				ans[(*itr).first] = c ^ (*itr).second;
			}
		}
		if (que.empty())
			break;
		a = que.front();
		que.pop();
	}
	for (i = 1; i <= num; i++)
		printf("%d\n", ans[i]);
	return 0;
}