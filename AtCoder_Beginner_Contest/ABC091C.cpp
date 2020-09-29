#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, a, b, buf, bp, ans = 0;
	cin >> num;
	vector<int> d(2 * num), red(num), blue(num);
	vector<bool> ok(num, true);
	for (; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		d[a] = b;
		red[i] = a;
	}
	for (i = 0; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		d[a] = b;
		blue[i] = a;
	}
	sort(red.begin(), red.end());
	sort(blue.begin(), blue.end());
	for (b = 0; b < num; b++) {
		buf = -1;
		for (a = 0; a < num && red[a] < blue[b]; a++) {
			if (ok[a] && d[red[a]] < d[blue[b]] && d[red[a]] > buf) {
				buf = d[red[a]];
				bp = a;
			}
		}
		if (buf != -1) {
			ok[bp] = false;
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}