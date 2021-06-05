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
	int num, i, j, m, x, y, ans = INF;
	cin >> num;
	vector<int> d(num);
	vector<vector<int>> a(num, vector<int>(num)), ng(num, vector<int>(num, 0));
	rep(i, num) {
		d[i] = i;
		rep(j, num) {
			cin >> a[i][j];
		}
	}
	cin >> m;
	rep(i, m) {
		cin >> x >> y;
		ng[--x][--y] = 1;
		ng[y][x] = 1;
	}
	do {
		int ok = 1;
		rep(i, num - 1) {
			if (ng[d[i]][d[i + 1]]) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			int sum = 0;
			rep(i, num)
				sum += a[d[i]][i];
			chmin(ans, sum);
		}
	} while (next_permutation(d.begin(), d.end()));
	if (ans == INF)
		printf("-1\n");
	else
		cout << ans << "\n";
	return 0;
}