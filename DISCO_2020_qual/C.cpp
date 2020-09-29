#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pp;
 
int main(void) {
	int num, i, j, a, h, w, k, x = 0;
	cin >> h >> w >> k;
	vector<string> d(h);
	vector<vector<int>> ans(h, vector<int>(w, 0));
	rep(i, h)
		cin >> d[i];
	rep(i, h) {
		a = d[i].find("#");
		if (a < 0 || a >= w)
			continue;
		x++;
		rep(j, a + 1)
			ans[i][j] = x;
		for (; j < w; j++) {
			if (d[i][j] == '#')
				x++;
			ans[i][j] = x;
		}
	}
	for(i = 1; i < h; i++) {
		if (ans[i][0] == 0) {
			rep(j, w)
				ans[i][j] = ans[i - 1][j];
		}
	}
	for (i = h - 2; i >= 0; i--) {
		if (ans[i][0] == 0) {
			rep(j, w)
				ans[i][j] = ans[i + 1][j];
		}
	}
	rep(i, h) {
		rep(j, w) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}