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
	int num, i, j, lx, ly, rx, ry;
	cin >> num;
	vector<vector<int>> d(1001, vector<int>(1001, 0));
	vector<int> ans(num + 1, 0);
	rep(i, num) {
		cin >> lx >> ly >> rx >> ry;
		d[lx][ly]++;
		d[rx][ry]++;
		d[lx][ry]--;
		d[rx][ly]--;
	}
	rep(i, 1000) {
		d[i + 1][0] += d[i][0];
		d[0][i + 1] += d[0][i];
	}
	rep(i, 1000) {
		rep(j, 1000) {
			d[i + 1][j + 1] += d[i][j + 1] + d[i + 1][j] - d[i][j];
			ans[d[i][j]]++;
		}
	}
	for (i = 1; i <= num; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}