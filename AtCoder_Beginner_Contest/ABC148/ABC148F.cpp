#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

queue<int> que;
void Search(int n, const vector<list<int>>& mp, vector<int>& d) {
	for (auto i = mp[n].begin(); i != mp[n].end(); i++) {
		if (d[*i] < 0) {
			que.push(*i);
			d[*i] = d[n] + 1;
		}
	}
	if (que.empty())
		return;
	n = que.front();
	que.pop();
	Search(n, mp, d);
	return;
}

int main(void) {
	int num, i, s, t, a, b, ans = 0;
	cin >> num >> s >> t;
	vector<list<int>> mp(num + 1);
	vector<int> x(num + 1, -1), y(num + 1, -1);
	for (i = 1; i < num; i++) {
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	x[s] = 0;
	y[t] = 0;
	Search(s, mp, x);
	Search(t, mp, y);
	for (i = 1; i <= num; i++) {
		if (mp[i].size() == 1 && x[i] < y[i]) {
			ans = max(ans, y[i] - 1);
		}
	}
	cout << ans << "\n";
	return 0;
}