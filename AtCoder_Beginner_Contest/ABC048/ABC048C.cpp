#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, k, i = 0;
	long long ans = 0, buf;
	cin >> num >> k;
	vector<int> d(num);
	for (; i < num; i++) {
		scanf_s("%d", &d[i]);
		if (d[i] > k) {
			ans += d[i] - k;
			d[i] = k;
		}
	}
	for (i = 1; i < num; i++) {
		buf = max(d[i - 1] + d[i] - k, 0);
		if (buf) {
			ans += buf;
			d[i] -= buf;
			if (d[i] < 0) {
				d[i - 1] += d[i];
				d[i] = 0;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}