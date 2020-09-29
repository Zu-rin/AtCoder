#include <iostream>
#include <vector>
#include <list>

using namespace std;

int num = 0;

void Show(vector<vector<int>> &data, vector<list<int>> &ans, int a, int b, int c, int d) {
	if (data[a][b] & 1) {
		ans[0].push_back(a);
		ans[1].push_back(b);
		ans[2].push_back(c);
		ans[3].push_back(d);
		data[c][d]++;
		num++;
	}
	return;
}

int main(void) {
	int h, w, i, j;
	cin >> h >> w;
	h++; w++;
	vector<vector<int>> d(h, vector<int>(w, 0));
	vector<list<int>> ans(4);
	for (i = 1; i < h; i++) {
		for (j = 1; j < w; j++) {
			scanf_s("%d", &d[i][j]);
		}
	}
	for (i = 1, j = 1; i < h; i++) {
		for (; j < w - 1; j++)
			Show(d, ans, i, j, i, j + 1);
		if (i == h - 1)
			break;
		Show(d, ans, i, j, i + 1, j);
		i++;

		for (; j > 1; j--)
			Show(d, ans, i, j, i, j - 1);
		if (i == h - 1)
			break;
		Show(d, ans, i, j, i + 1, j);
	}
	cout << num << "\n";
	auto i0 = ans[0].begin();
	auto i1 = ans[1].begin();
	auto i2 = ans[2].begin();
	auto i3 = ans[3].begin();
	for (; i0 != ans[0].end(); i0++, i1++, i2++, i3++)
		printf("%d %d %d %d\n", *i0, *i1, *i2, *i3);
	return 0;
}