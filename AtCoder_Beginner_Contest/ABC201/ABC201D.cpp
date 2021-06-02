#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int score(int y, int x, vector<string> &s) {
	if (y == 0 and x == 0)
		return 0;
	return (s[y][x] == '-') ^ ((y + x) & 1) ? 1 : -1;
}

int main(void) {
	int h, w, num, i, j;
	cin >> h >> w;
	vector<string> s(h);
	vector<vector<int>> d(h, vector<int>(w, 0));
	rep(i, h)
		cin >> s[i];
	d[h - 1][w - 1] = score(h - 1, w - 1, s);
	for (i = h - 2; i >= 0; i--)
		d[i][w - 1] = d[i + 1][w - 1] + score(i, w - 1, s);
	for (i = w - 2; i >= 0; i--)
		d[h - 1][i] = d[h - 1][i + 1] + score(h - 1, i, s);
	for (i = h - 2; i >= 0; i--) {
		for (j = w - 2; j >= 0; j--) {
			if ((i + j) & 1) {
				d[i][j] = min(d[i + 1][j], d[i][j + 1]) + score(i, j, s);
			}
			else {
				d[i][j] = max(d[i + 1][j], d[i][j + 1]) + score(i, j, s);
			}
		}
	}
	if (d[0][0] == 0)
		printf("Draw\n");
	else if(d[0][0] > 0)
		printf("Takahashi\n");
	else
		printf("Aoki\n");
	return 0;
}