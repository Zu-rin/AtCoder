#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Search(int n, int x, vector<int> &d) {
	if (n == 13) {
		int a = 0, b = 1, ans = 12;
		while (x > 0) {
			if (x & 1) {
				ans = min(ans, b - a);
				a = b;
			}
			x >>= 1;
			b++;
		}
		return min(ans, 24 - a);
	}
	if (d[n] == 0)
		return Search(n + 1, x, d);
	if (d[n] == 1)
		return max(Search(n + 1, x + (1 << (n - 1)), d), Search(n + 1, x + (1 << (23 - n)), d));
	return Search(n + 1, x + (1 << (n - 1)) + (1 << (23 - n)), d);
}

int main(void) {
	int num, i, a, ans = 1;
	cin >> num;
	vector<int> d(13, 0);
	d[0] = 1;
	for (i = 0; i < num; i++) {
		scanf_s("%d", &a);
		d[a]++;
	}
	if (d[0] > 1 || d[12] > 1)
		ans = 0;
	for (i = 1; i < 12; i++) {
		if (d[i] > 2)
			ans = 0;
	}
	if (ans > 0)
		ans = Search(1, 0, d);
	cout << ans << "\n";
	return 0;
}