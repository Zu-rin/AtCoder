#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define INF 1000000000

using namespace std;

queue<pair<int, int>> que;
int h, w;

void Search(vector<vector<int>> &d) {
	if (que.empty())
		return;
	int i = que.front().first, j = que.front().second;
	if (i > 0 && d[i - 1][j] == INF) {
		que.push(make_pair(i - 1, j));
		d[i - 1][j] = d[i][j] + 1;
	}
	if (j > 0 && d[i][j - 1] == INF) {
		que.push(make_pair(i, j - 1));
		d[i][j - 1] = d[i][j] + 1;
	}
	if (i < h - 1 && d[i + 1][j] == INF) {
		que.push(make_pair(i + 1, j));
		d[i + 1][j] = d[i][j] + 1;
	}
	if (j < w - 1 && d[i][j + 1] == INF) {
		que.push(make_pair(i, j + 1));
		d[i][j + 1] = d[i][j] + 1;
	}
	que.pop();
	Search(d);
}

int main(void) {
	int i, j, ans = 0;
	cin >> h >> w;
	vector<vector<int>> d(h, vector<int>(w, INF));
	vector<string> s(h);
	for (i = 0; i < h; i++) {
		cin >> s[i];
		for (j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				d[i][j] = 0;
				que.push(make_pair(i, j));
			}
		}
	}
	Search(d);
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++)
			ans = max(ans, d[i][j]);
	}
	cout << ans << "\n";
	return 0;
}