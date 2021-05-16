#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, k, i = 0;
	double ans = 0.0;
	cin >> num >> k;
	vector<int> d(num);
	for (; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	for (i = num - k; i < num; i++) {
		ans = (ans + d[i]) / 2;
	}
	printf("%lf\n", ans);
	return 0;
}