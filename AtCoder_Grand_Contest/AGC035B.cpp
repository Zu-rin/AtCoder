#include <iostream>
#include <map>
#include <vector>
#include <list>

using namespace std;

int num, m;

int Search(int n, vector<list<int>> &d, vector<pair<int, int>> &edge, vector<int> &e, list<pair<int, int>> &ans) {
	int tag;
	if (d[n].size() & 1) {
		for (auto itr = d[n].begin(); itr != d[n].end(); itr++) {
			if (e[*itr] == 2) {
				e[*itr]--;
				d[n].erase(itr);
				break;
			}
		}
		if (d[n].size() & 1) {
			auto itr = d[n].begin();
			d[n].erase(itr);
		}
	}
	for (auto itr = d[n].begin(); itr != d[n].end(); itr++) {
		if (edge[*itr].first == n)
			tag = edge[*itr].second;
		else
			tag = edge[*itr].first;
		ans.push_back(make_pair(n, tag));
		for (auto ii = d[tag].begin(); ii != d[tag].end(); ii++) {
			if (*itr == *ii) {
				d[tag].erase(ii);
				break;
			}
		}
	}
	return 0;
}

int main(void) {
	int i, a, b;
	cin >> num >> m;
	vector<list<int>> d(num + 1);
	vector<int> e(m, 2);
	vector<pair<int, int>> edge(m);
	list<pair<int, int>> ans;
	for (i = 0; i < m; i++) {
		scanf_s("%d%d", &a, &b);
		edge[i] = make_pair(a, b);
		d[a].push_back(i);
		d[b].push_back(i);
	}
	for (i = 1; i <= num; i++) {
		Search(i, d, edge, e, ans);
	}
	if (ans.size() != m)
		printf("-1\n");
	else {
		for (auto itr = ans.begin(); itr != ans.end(); itr++) {
			printf("%d %d\n", (*itr).first, (*itr).second);
		}
	}
	return 0;
}