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

int h, w;

void Side(vector<vector<int>> d, vector<vector<int>> &ans) {
	int i, j;
	rep(i, h) {
		rep(j, w - 1) {
			if (d[i][j] == 1 && d[i][j + 1] == 0)
				d[i][j + 1] = 1;
		}
		for (j = w - 1; j > 0; j--) {
			if (d[i][j] == 1 && d[i][j - 1] == 0)
				d[i][j - 1] = 1;
		}
		rep(j, w) {
			if (d[i][j] == 1)
				ans[i][j] = 1;
		}
	}
	return;
}

void Vert(vector<vector<int>> d, vector<vector<int>>& ans) {
	int i, j;
	rep(j, w) {
		rep(i, h - 1) {
			if (d[i][j] == 1 && d[i + 1][j] == 0)
				d[i + 1][j] = 1;
		}
		for (i = h - 1; i > 0; i--) {
			if (d[i][j] == 1 && d[i - 1][j] == 0)
				d[i - 1][j] = 1;
		}
		rep(i, h) {
			if (d[i][j] == 1)
				ans[i][j] = 1;
		}
	}
	return;
}

int main(void) {
	int n, m, i, j, a, b;
	ll ans = 0;
	cin >> h >> w >> n >> m;
	vector<vector<int>> d(h, vector<int>(w, 0)), s(h, vector<int>(w, 0));
	rep(i, n) {
		cin >> a >> b;
		d[a - 1][b - 1] = 1;
	}
	rep(i, m) {
		cin >> a >> b;
		d[a - 1][b - 1] = -1;
	}
	Side(d, s);
	Vert(d, s);
	rep(i, h) {
		rep(j, w) {
			if (s[i][j])
				ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}