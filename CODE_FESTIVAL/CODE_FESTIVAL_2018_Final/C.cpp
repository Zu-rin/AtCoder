#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int Search(const int n, vector<pair<int, int>> &d, int l, int r) {
	if (l == r)
		return l;
	int p = (l + r) >> 1;
	if (n >= d[p].first)
		return Search(n, d, p + 1, r);
	else
		return Search(n, d, l, p);
}

int main(void) {
	int num, m, i, a, b;
	cin >> num;
	vector<pair<int, int>> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d%d", &d[i].first, &d[i].second);
	sort(d.begin(), d.end());
	cin >> m;
	for (i = 0; i < m; i++) {
		scanf_s("%d", &a);
		b = Search(a, d, 0, num);
		if (b >= num)
			printf("%d\n", d[b - 1].second + a - d[b - 1].first);
		else if (b > 0)
			printf("%d\n", min(d[b - 1].second + a - d[b - 1].first, d[b].second));
		else
			printf("%d\n", d[b].second);
	}
	return 0;
}