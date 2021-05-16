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

void Search(int n, vector<list<int>>& mp, vector<int>& d) {
	for (auto itr = mp[n].begin(); itr != mp[n].end(); itr++) {
		if (d[*itr]) {
			que.push(*itr);
			d[*itr] = false;
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
	int num, m, i, a, b, ans = 0;
	cin >> num >> m;
	vector<list<int>> mp(num + 1);
	vector<int> d(num + 1, true);
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	for (i = 1; i <= num; i++) {
		if (d[i]) {
			d[i] = false;
			Search(i, mp, d);
			ans++;
		}
	}
	cout << ans - 1  << "\n";
	return 0;
}