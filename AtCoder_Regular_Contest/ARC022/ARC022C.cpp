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

int Search(int s, vector<list<int>> & d) {
	int i, p = s;
	vector<int> ans(d.size(), INF);
	queue<int> que;
	ans[0] = ans[s] = 0;
	que.push(s);
	while (!que.empty()) {
		int n = que.front();
		que.pop();
		for (auto it = d[n].begin(); it != d[n].end(); it++) {
			if (ans[*it] == INF) {
				que.push(*it);
				ans[*it] = ans[n] + 1;
			}
		}
	}
	rep(i, ans.size()) {
		if (ans[p] < ans[i]) {
			p = i;
		}
	}
	return p;
}

int main(void) {
	int num, i, a, b;
	cin >> num;
	vector<list<int>> d(num + 1);
	rep(i, num - 1) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	a = Search(1, d);
	b = Search(a, d);
	printf("%d %d\n", a, b);
	return 0;
}