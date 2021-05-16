#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j, k, ok;
	ll ans = 0, sum = 0;
	cin >> num;
	vector<vector<int>> d(num, vector<int>(num, 0));
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			scanf_s("%d", &d[i][j]);
			ans += d[i][j];
		}
	}
	for (k = 0; k < num; k++) {
		for (i = 0; i < num; i++) {
			ok = false;
			for (j = 0; j < num; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					printf("-1\n");
					return 0;
				}
				if (d[k][i] == d[k][j] + d[j][i] && i != j && j != k) {
					ok = true;
				}
			}
			if (ok)
				sum += d[k][i];
		}
	}
	ans -= sum;
	ans >>= 1;
	cout << ans << "\n";
	return 0;
}