#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Search(const int a, const vector<int> &d, int l, int r) {
	if (l == r)
		return l;
	int p = (l + r) >> 1;
	if (a <= d[p])
		return Search(a, d, p + 1, r);
	else
		return Search(a, d, l, p);
}

int Search(const int a, const vector<int> &d) {
	return Search(a, d, 0, d.size() - 1);
}

int main(void) {
	int n, a, i, j, ans;
	scanf_s("%d", &n);
	vector<int> d(n + 1, 0);
	for (i = 2; i <= n; i++) {
		a = i;
		for (j = 2; j < n; j++) {
			while (a != 0 && a % j == 0) {
				d[j]++;
				a /= j;
			}
		}
	}
	sort(d.begin(), d.end(), greater<int>());
	ans = Search(74, d);
	a = Search(4, d);
	ans += Search(14, d) * (a - 1);
	ans += Search(24, d) * (Search(2, d) - 1);
	ans += a * (a - 1) * (Search(2, d) - 2) / 2;
	cout << ans << "\n";
	return 0;
}