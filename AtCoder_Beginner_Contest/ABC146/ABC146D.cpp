#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

typedef struct {
	int a, b;
} edge;

map<pair<int, int>, int> e;

int Search(int n, int p, vector<list<int>>& d, vector<int>& ans) {
	int i = 1, k = ans[e[make_pair(min(n, p), max(n, p))]], num;
	num = d[n].size();
	for (auto itr = d[n].begin(); itr != d[n].end(); itr++) {
		if (*itr == p)
			continue;
		if (i == k)
			i++;
		ans[e[make_pair(min(n, *itr), max(n, *itr))]] = i++;
		num = max(num, Search(*itr, n, d, ans));
	}
	return num;
}

int main(void) {
	int num, i, a, b;
	cin >> num;
	vector<list<int>> d(num + 1);
	vector<int> ans(num - 1);
	for (i = 0; i < num - 1; i++) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
		e[make_pair(a, b)] = i;
	}
	cout << Search(1, 0, d, ans) << "\n";
	for (i = 0; i < num - 1; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}