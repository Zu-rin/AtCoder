#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int i = 0, num, sum = 0, ans = 1 << 30;
	cin >> num;
	vector<int> d(num), a(num), b(num);
	for (; i < num; i++) {
		scanf_s("%d", &d[i]);
		sum += d[i];
		a[i] = sum;
	}
	for (sum = 0, i = num - 1; i >= 0; i--) {
		b[i] = sum;
		sum += d[i];
	}
	for (i = 0; i < num; i++)
		ans = min(ans, abs(a[i] - b[i]));
	cout << ans << "\n";
	return 0;
}