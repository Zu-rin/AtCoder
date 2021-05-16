#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, ans = 0;
	cin >> num;
	num <<= 1;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	for (i = 0; i < num; i += 2)
		ans += d[i];
	printf("%d\n", ans);
	return 0;
}