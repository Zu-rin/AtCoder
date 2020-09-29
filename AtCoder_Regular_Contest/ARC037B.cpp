#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int Search(int n, vector<vector<int>> &d, vector<int> &a) {
	int i, ok = true;
	a[n] = false;
	for (i = 0; i < d[n].size(); i++) {
		if (d[n][i]) {
			if (a[i]) {
				d[i][n] = false;
				ok &= Search(i, d, a);
			}
			else
				ok = false;
		}
	}
	return ok;
}

int main(void) {
	int num, m, i, a, b, ans = 0;
	cin >> num >> m;
	vector<vector<int>> d(num + 1, vector<int>(num + 1, 0));
	vector<int> k(num + 1, true);
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		d[a][b] = true;
		d[b][a] = true;
	}
	for (i = 1; i <= num; i++) {
		if (k[i] && Search(i, d, k)) {
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}