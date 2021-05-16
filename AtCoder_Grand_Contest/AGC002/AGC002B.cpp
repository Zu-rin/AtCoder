#include <iostream>
#include <vector>
#define T true
#define F false

using namespace std;

int main(void) {
	int n, m, x, y, i, ans = 0;
	cin >> n >> m;
	vector<int> d(n + 1, 1), a(n + 1, F);
	a[1] = T;
	for (i = 0; i < m; i++) {
		scanf_s("%d%d", &x, &y);
		d[x]--;
		d[y]++;
		if (a[x]) {
			a[y] = T;
			if (d[x] == 0)
				a[x] = F;
		}
	}
	for (i = 1; i <= n; i++) {
		if (a[i])
			ans++;
	}
	cout << ans << "\n";
	return 0;
}