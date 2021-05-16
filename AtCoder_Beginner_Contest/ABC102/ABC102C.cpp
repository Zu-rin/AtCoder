#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, b;
	long long sum = 0, ans = 0;
	cin >> num;
	vector<int> d(num);
	for (; i < num; i++) {
		scanf_s("%d", &d[i]);
		d[i] -= i + 1;
	}
	sort(d.begin(), d.end());
	b = d[num >> 1];
	for (i = 0; i < num; i++)
		ans += abs(d[i] - b);
	b = d[(num >> 1) - 1];
	for (sum = 0, i = 0; i < num; i++)
		sum += abs(d[i] - b);
	ans = min(ans, sum);
	cout << ans << "\n";
	return 0;
}