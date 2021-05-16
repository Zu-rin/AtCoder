#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, m, q, i, j, a, b;
	cin >> num >> m >> q;
	vector<vector<int>> d(num + 1, vector<int>(num + 1, 0));
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		d[a][b]++;
	}
	for (i = 1; i <= num; i++) {
		for (j = 1; j <= num; j++) {
			d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
		}
	}
	for (i = 0; i < q; i++) {
		cin >> a >> b;
		cout << d[b][b] - d[a - 1][b] << "\n";
	}
	return 0;
}