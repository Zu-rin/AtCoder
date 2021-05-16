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

int main(void) {
	int h, w, num, i, j;
	cin >> h >> w;
	vector<string> s(h);
	vector<vector<ll>> x(h + 1, vector<ll>(w + 1, 0)), y(h + 1, vector<ll>(w + 1, 0)), z(h + 1, vector<ll>(w + 1, 0)), ans(h, vector<ll>(w, 0));
	ans[0][0] = 1;
	rep(i, h)
		cin >> s[i];
	rep(i, h) {
		rep(j, w) {
			if (s[i][j] == '#')
				continue;
			if (!ans[i][j])
				ans[i][j] = (x[i][j] + y[i][j] + z[i][j]) % MOD;
			x[i][j + 1] = (x[i][j] + ans[i][j]) % MOD;
			y[i + 1][j] = (y[i][j] + ans[i][j]) % MOD;
			z[i + 1][j + 1] = (z[i][j] + ans[i][j]) % MOD;
		}
	}
	cout << ans[h - 1][w - 1] << "\n";
	return 0;
}