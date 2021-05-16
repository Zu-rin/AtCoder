#include <iostream>
#include <vector>
#include <queue>
#define T true
#define F false

using namespace std;

int num, m, tag;
queue<int> nx;

bool Search(int n, vector<vector<bool>> &map, vector<bool> &d) {
	if (n == tag) {
		while (!nx.empty())
			nx.pop();
		return F;
	}
	for (int i = 0; i < num; i++) {
		if (map[n][i] && d[i]) {
			nx.push(i);
			d[i] = F;
		}
	}
	if (nx.empty())
		return T;
	n = nx.front();
	nx.pop();
	return Search(n, map, d);
}

int main(void) {
	int i = 0, ans = 0;
	cin >> num >> m;
	vector<int> a(m), b(m);
	vector<vector<bool>> map(num, vector<bool>(num, F));
	for (; i < m; i++) {
		scanf_s("%d%d", &a[i], &b[i]);
		map[--a[i]][--b[i]] = T;
		map[b[i]][a[i]] = T;
	}
	for (i = 0; i < m; i++) {
		tag = b[i];
		map[a[i]][tag] = F;
		map[tag][a[i]] = F;
		vector<bool> d(m, T);
		if (Search(a[i], map, d))
			ans++;
		map[a[i]][tag] = T;
		map[tag][a[i]] = T;
	}
	cout << ans << "\n";
	return 0;
}