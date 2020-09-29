#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Search(vector<int> &d, int data, int st, int ed) {
	int v = (st + ed) / 2;
	if (d[v] == data)
		return v + 1;
	else if (d[v] > data)
		return Search(d, data, st, v);
	else
		return Search(d, data, v + 1, ed);
}

int main(void) {
	int pnum, num, i = 0, pp, yy;
	cin >> pnum >> num;
	vector<int> p(num), y(num);
	vector<vector<int>> d(pnum, vector<int>());
	for (i = 0; i < num; i++) {
		scanf_s("%d%d", &p[i], &y[i]);
		d[p[i] - 1].push_back(y[i]);
	}
	for (i = 0; i < pnum; i++)
			sort(d[i].begin(), d[i].end());
	for (i = 0; i < num; i++) {
		printf("%06d%06d\n", p[i], Search(d[p[i] - 1], y[i], 0, d[p[i] - 1].size() - 1));
	}
	return 0;
}