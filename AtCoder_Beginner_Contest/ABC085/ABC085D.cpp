#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, h, i, a, maxa = 0, ans = 0;
	cin >> num >> h;
	vector<int> b(num);
	for (i = 0; i < num; i++) {
		scanf_s("%d%d", &a, &b[i]);
		maxa = max(maxa, a);
	}
	sort(b.begin(), b.end(), greater<int>());
	for (i = 0; i < num; i++) {
		if (maxa > b[i] || h <= 0)
			break;
		h -= b[i];
		ans++;
	}
	if (h > 0) {
		ans += h / maxa;
		if (h % maxa)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}