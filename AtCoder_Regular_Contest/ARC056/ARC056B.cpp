#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

void Search(int s, vector<list<int>> &d, vector<int> &ans) {
	int i;
	priority_queue<pp> que;
	que.push(pp(s, s));
	while (!que.empty()) {
		int a = que.top().first, n = que.top().second;
		que.pop();
		if (!ans[n]) {
			ans[n] = a;
			for (auto it = d[n].begin(); it != d[n].end(); it++) {
				if (!ans[*it]) {
					que.push(pp(min(a, *it), *it));
				}
			}
		}
	}
	return;
}

int main(void) {
	int num, m, s, i, a, b;
	cin >> num >> m >> s;
	vector<int> ans(num + 1, 0);
	vector<list<int>> d(num + 1);
	rep(i, m) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	Search(s, d, ans);
	for (i = 1; i <= num; i++) {
		if (i == ans[i])
			printf("%d\n", i);
	}
	return 0;
}