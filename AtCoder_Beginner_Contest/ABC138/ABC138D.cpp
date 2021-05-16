#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;

queue<int> que;

void Search(int n, vector<list<int>> &e, vector<int> &ok, vector<ll> &ans) {
	ok[n] = false;
	for (auto itr = e[n].begin(); itr != e[n].end(); itr++) {
		if (ok[*itr]) {
			que.push(*itr);
			ans[*itr] += ans[n];
		}
	}
	if (que.empty())
		return;
	n = que.front();
	que.pop();
	Search(n, e, ok, ans);
	return;
}

int main(void) {
	int num, q, i, a, b;
	cin >> num >> q;
	vector<list<int>> e(num + 1);
	vector<int> ok(num + 1, true);
	vector<ll> ans(num + 1, 0);
	for (i = 0; i < num - 1; i++) {
		scanf_s("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (i = 0; i < q; i++) {
		scanf_s("%d%d", &a, &b);
		ans[a] += b;
	}
	Search(1, e, ok, ans);
	for (i = 1; i <= num; i++)
		printf("%lld ", ans[i]);
	printf("\n");
	return 0;
}