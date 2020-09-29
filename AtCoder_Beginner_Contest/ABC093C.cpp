#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int ans = 0, ma;
	vector<int> d(3);
	scanf_s("%d%d%d", &d[0], &d[1], &d[2]);
	if ((d[0] & 1) != (d[1] & 1)) {
		if ((d[0] & 1) == (d[2] & 1))
			d[0]++;
		else
			d[1]++;
		d[2]++;
		ans++;
	}
	else if ((d[0] & 1) != (d[2] & 1)) {
		d[0]++;
		d[1]++;
		ans++;
	}
	ma = max(d[0], d[1]);
	ma = max(ma, d[2]);
	ans += (ma - d[0]) / 2 + (ma - d[1]) / 2 + (ma - d[2]) / 2;
	cout << ans << "\n";
	return 0;
}