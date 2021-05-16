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
	int num = 12800, i, j, k, h, w, a;
	cin >> h >> w;
	vector<vector<int>> d(h + 1, vector<int>(w + 1, 0));
	vector<vector<vector<char>>> dp(h + 1, vector<vector<char>>(w + 1, vector<char>(num + 1, 0)));
	rep(i, h) {
		rep(j, w) {
			cin >> d[i][j];
		}
	}
	rep(i, h) {
		rep(j, w) {
			cin >> a;
			d[i][j] -= a;
			d[i][j] = abs(d[i][j]);
		}
	}
	dp[0][0][d[0][0]] = 1;
	rep(i, h) {
		rep(j, w) {
			rep(k, num) {
				if (dp[i][j][k]) {
					dp[i][j + 1][min(k + d[i][j + 1], num)] = 1;
					dp[i][j + 1][abs(k - d[i][j + 1])] = 1;
					dp[i + 1][j][min(k + d[i + 1][j], num)] = 1;
					dp[i + 1][j][abs(k - d[i + 1][j])] = 1;
				}
			}
		}
	}
	vector<char>& x = dp[h - 1][w - 1];
	rep(k, x.size()) {
		if (x[k])
			break;
	}
	cout << k << "\n";
	return 0;
}