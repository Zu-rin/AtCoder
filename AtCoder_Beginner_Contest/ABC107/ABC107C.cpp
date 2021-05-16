#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, k, i = 0, ans;
	cin >> num >> k;
	vector<int> d(num);
	for (; i < num; i++)
		scanf_s("%d", &d[i]);
	ans = (d[num - 1] - d[0]) * 2;
	for (i = 0; i <= num - k; i++)
		ans = min(ans, abs(d[i]) + d[i + k - 1] - d[i]);
	for (i = num - 1; i >= k - 1; i--)
		ans = min(ans, abs(d[i]) + d[i] - d[i - k + 1]);
	printf("%d\n", ans);
	return 0;
}