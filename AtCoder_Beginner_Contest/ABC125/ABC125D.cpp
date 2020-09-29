#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, a, i, n = 0, mi = 1 << 30;
	long long ans = 0;
	cin >> num;
	for (i = 0; i < num; i++) {
		scanf_s("%d", &a);
		ans += abs(a);
		if (a < 0)
			n++;
		mi = min(mi, abs(a));
	}
	if (n & 1)
		ans -= mi << 1;
	cout << ans << "\n";
	return 0;
}