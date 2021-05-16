#include <iostream>
#include <vector>
#include <string>
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

int main(void) {
	int num, i, j, h, w;
	cin >> h >> w;
	vector<string> s(h);
	vector<vector<int>> d(h, vector<int>(w, INF));
	rep(i, h)
		cin >> s[i];
	if (s[0][0] == '#')
		d[0][0] = 1;
	else
		d[0][0] = 0;
	rep(i, h) {
		rep(j, w) {
			if (i + 1 < h) {
				if (s[i][j] == '.' && s[i + 1][j] == '#')
					chmin(d[i + 1][j], d[i][j] + 1);
				else
					chmin(d[i + 1][j], d[i][j]);
			}
			if (j + 1 < w) {
				if (s[i][j] == '.' && s[i][j + 1] == '#')
					chmin(d[i][j + 1], d[i][j] + 1);
				else
					chmin(d[i][j + 1], d[i][j]);
			}
		}
	}
	cout << d[h - 1][w - 1] << "\n";
	return 0;
}