#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define INF -3

using namespace std;
typedef long long ll;

queue<pair<int, int>> que;
pair<int, int> s, e;

int Search(pair<int, int> n, map<pair<int, int>, vector<pair<int, int>>> &nx, map<pair<int, int>, int> &d) {
	if (n == e)
		return d[n];
	for (int i = 0; i < nx[n].size(); i++) {
		if (d[nx[n][i]] == INF) {
			d[nx[n][i]] = d[n] + 1;
			que.push(nx[n][i]);
		}
	}
	if (que.empty())
		return INF;
	n = que.front();
	que.pop();
	return Search(n, nx, d);
}

int main(void) {
	int num, edg, i, a, b;
	cin >> num >> edg;
	map<pair<int, int>, vector<pair<int, int>>> mp;
	map<pair<int, int>, int> d;
	for (i = 1; i <= num; i++) {
		d[make_pair(i, 0)] = INF;
		d[make_pair(i, 1)] = INF;
		d[make_pair(i, 2)] = INF;
	}
	for (i = 0; i < edg; i++) {
		scanf_s("%d%d", &a, &b);
		mp[make_pair(a, 0)].push_back(make_pair(b, 1));
		mp[make_pair(a, 1)].push_back(make_pair(b, 2));
		mp[make_pair(a, 2)].push_back(make_pair(b, 0));
	}
	cin >> s.first >> e.first;
	s.second = 0;
	e.second = 0;
	d[s] = 0;
	a = Search(s, mp, d);
	printf("%d\n", a / 3);
	return 0;
}