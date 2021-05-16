#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int h, w;
queue<pair<int, int>> que;

int Search(int a, int b, vector<string> &d, vector<vector<int>> &k) {
	if (a == h - 1 && b == w - 1)
		return true;
	if (a > 0 && d[a - 1][b] == '.') {
		que.push(make_pair(a - 1, b));
		k[a - 1][b] = k[a][b] + 1;
		d[a - 1][b] = '#';
	}
	if (b > 0 && d[a][b - 1] == '.') {
		que.push(make_pair(a, b - 1));
		k[a][b - 1] = k[a][b] + 1;
		d[a][b - 1] = '#';
	}
	if (a < h - 1 && d[a + 1][b] == '.') {
		que.push(make_pair(a + 1, b));
		k[a + 1][b] = k[a][b] + 1;
		d[a + 1][b] = '#';
	}
	if (b < w - 1 && d[a][b + 1] == '.') {
		que.push(make_pair(a, b + 1));
		k[a][b + 1] = k[a][b] + 1;
		d[a][b + 1] = '#';
	}
	if (que.empty())
		return false;
	a = que.front().first;
	b = que.front().second;
	que.pop();
	return Search(a, b, d, k);
}

int main(void) {
	int sum = 0, i, j;
	cin >> h >> w;
	vector<string> d(h);
	vector<vector<int>> k(h, vector<int>(w, 0));
	k[0][0] = 1;
	d[0][0] = '#';
	for (i = 0; i < h; i++) {
		cin >> d[i];
		for (j = 0; j < w; j++) {
			if (d[i][j] == '.')
				sum++;
		}
	}
	if (Search(0, 0, d, k))
		printf("%d\n", sum - k[h - 1][w - 1]);
	else
		printf("-1\n");
	return 0;
}