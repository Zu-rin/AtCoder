#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

void Move(int y, int x, vector<string>& d, vector<string>& ans) {
	int n = d[y++][x] - '0';
	ans[y][x] += n;
	d[y - 1][x] -= n;
	d[y][x - 1] -= n;
	d[y + 1][x] -= n;
	d[y][x + 1] -= n;
	return;
}

int main(void) {
	int n, m, i, j;
	cin >> n >> m;
	vector<string> d(n), ans(n, "");
	for (i = 0; i < m; i++)
		ans[0] += "0";
	for (i = 1; i < n; i++)
		ans[i] = ans[0];
	for (i = 0; i < n; i++)
		cin >> d[i];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (d[i][j] > '0') {
				Move(i, j, d, ans);
			}
		}
	}
	for (i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}