#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int main(void) {
	int num, k, a, b, ans = 0, i, j;
	ll dis;
	cin >> num >> k;
	vector<vector<int>> d(num, vector<int>(k));
	for (i = 0; i < num; i++) {
		for (j = 0; j < k; j++)
			scanf_s("%d", &d[i][j]);
	}
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			dis = 0;
			for (a = 0; a < k; a++) {
				dis += (d[i][a] - d[j][a]) * (d[i][a] - d[j][a]);
			}
			b = sqrt(dis);
			if (b * b == dis)
				ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}