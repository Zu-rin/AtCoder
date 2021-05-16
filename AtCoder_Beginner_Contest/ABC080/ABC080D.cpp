#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, m, i, j, a, b, c, ans = 0;
	cin >> num >> m;
	vector<vector<int>> d(m, vector<int>(100001, 0));
	for (i = 0; i < num; i++) {
		scanf_s("%d%d%d", &a, &b, &c);
		d[c - 1][a]++;
		d[c - 1][b]--;
	}
	for (i = 0; i < m; i++) {
		for (j = 1; j < 100000; j++) {
			if (d[i][j] > 0) {
				d[i][j - 1] += 1;
				d[i][j] = 0;
			}
		}
	}
	for (a = 0, i = 0; i < d[0].size(); i++) {
		for(j = 0; j < m; j++)
			a += d[j][i];
		ans = max(ans, a);
	}
	cout << ans << "\n";
	return 0;
}