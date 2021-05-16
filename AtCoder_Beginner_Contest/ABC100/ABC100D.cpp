#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, m, i, j;
	ll x, y, z, ans = 0;
	cin >> num >> m;
	vector<vector<ll>> d(8, vector<ll>(num, 0));
	for (i = 0; i < num; i++) {
		cin >> x >> y >> z;
		d[0][i] = x + y + z;
		for (j = 1; j < 8; j++) {
			d[j][i] = d[0][i];
			if (j & 1)
				d[j][i] -= x << 1;
			if (j & 2)
				d[j][i] -= y << 1;
			if (j & 4)
				d[j][i] -= z << 1;
		}
	}
	for (i = 0; i < 8; i++) {
		sort(d[i].begin(), d[i].end(), greater<ll>());
		for (x = 0, j = 0; j < m; j++)
			x += d[i][j];
		ans = max(ans, x);
	}
	cout << ans << "\n";
	return 0;
}