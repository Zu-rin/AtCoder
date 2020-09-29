#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i;
	long long ans = 0;
	cin >> num;
	vector<int> a(num + 1, 0), b(num, 0);
	for (i = 0; i <= num; i++)
		scanf_s("%d", &a[i]);
	for (i = 0; i < num; i++)
		scanf_s("%d", &b[i]);
	for (i = 0; i < num; i++) {
		ans += min(a[i], b[i]) + min(a[i + 1], max(0, b[i] - a[i]));
		a[i + 1] -= min(a[i + 1],max(0, b[i] - a[i]));
	}
	printf("%lld\n", ans);
	return 0;
}