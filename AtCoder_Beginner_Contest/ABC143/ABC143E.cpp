#pragma optimize("O3")
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
	int num, m, i, j, k, a, b, q;
	ll l;
	cin >> num >> m >> l;
	vector<vector<ll>> d(num, vector<ll>(num, INF));
	vector<vector<int>> ans(num, vector<int>(num, 500));
	rep(i, m) {
		cin >> a >> b;
		a--, b--;
		cin >> d[a][b];
		d[b][a] = d[a][b];
	}
	rep(i, num)
		d[i][i] = 0;
	rep(k, num) {
		rep(i, num) {
			rep(j, num)
				chmin(d[i][j], d[i][k] + d[k][j]);
		}
	}
	rep(i, num) {
		for (j = i + 1; j < num; j++) {
			if (d[i][j] <= l)
				ans[i][j] = ans[j][i] = 1;
		}
	}
	rep(k, num) {
		rep(i, num) {
			rep(j, num)
				chmin(ans[i][j], ans[i][k] + ans[k][j]);
		}
	}
	cin >> q;
	rep(i, q) {
		cin >> a >> b;
		a--, b--;
		if (ans[a][b] == 500)
			printf("-1\n");
		else
			cout << ans[a][b] - 1 << "\n";
	}
	return 0;
}