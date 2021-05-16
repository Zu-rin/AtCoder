#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Par(int n, vector<int> &a) {
	if (n == a[n])
		return n;
	int ans = Par(a[n], a);
	a[n] = ans;
	return ans;
}

int main(void) {
	int num, m, i, x, y, ans = 0;
	cin >> num >> m;
	vector<int> d(num + 1), a(num + 1), h(num + 1, 0);
	for (i = 1; i <= num; i++) {
		scanf_s("%d", &d[i]);
		a[i] = i;
	}
	for (i = 0; i < m; i++) {
		scanf_s("%d%d", &x, &y);
		x = Par(x, a);
		y = Par(y, a);
		if (x != y) {
			if (h[x] == h[y]) {
				a[max(x, y)] = min(x, y);
				h[max(x, y)]++;
			}
			else if (h[x] < h[y])
				a[x] = y;
			else
				a[y] = x;
		}
	}
	for (i = 1; i <= num; i++) {
		if (Par(i, a) == Par(d[i], a))
			ans++;
	}
	cout << ans << "\n";
	return 0;
}