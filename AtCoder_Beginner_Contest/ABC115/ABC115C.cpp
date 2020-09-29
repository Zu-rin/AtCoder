#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, k, i = 0, ans = 1000000000;
	cin >> num >> k;
	vector<int> d(num);
	for (; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	k--;
	for (i = 0; i < num - k; i++)
		ans = min(ans, d[i + k] - d[i]);
	printf("%d\n", ans);
	return 0;
}