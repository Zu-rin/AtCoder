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

char Judge(int i, int j, vector<string> &m) {
	int di[4] = { -1, 0, 1, 0 }, dj[4] = { 0, 1, 0, -1 }, k;
	vector<int> ok(6, 1);
	rep(k, 4) {
		if (m[i + di[k]][j + dj[k]] != '.')
			ok[m[i + di[k]][j + dj[k]] - '0'] = 0;
	}
	for (k = 1; k <= 5; k++) {
		if (ok[k])
			break;
	}
	return (char)('0' + k);
}

int main(void) {
	int num, i, h, w;
	cin >> h >> w;
	string s;
	vector<string> m(h + 2, string(w + 2, '0'));
	for (i = 1; i <= h; i++) {
		cin >> s;
		m[i] = "0" + s + "0";
	}
	for (i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (m[i][j] == '.') {
				m[i][j] = Judge(i, j, m);
			}
			printf("%c", m[i][j]);
		}
		printf("\n");
	}
	return 0;
}