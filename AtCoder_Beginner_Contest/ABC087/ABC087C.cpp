#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, sum = 0, ans = 0;
	cin >> num;
	vector<int> top(num), flo(num), a(num);
	for (; i < num; i++)
		scanf_s("%d", &top[i]);
	for (i = 0; i < num; i++)
		scanf_s("%d", &flo[i]);
	for (i = 0; i < num; i++) {
		sum += top[i];
		a[i] = sum;
	}
	for (i = num - 1, sum = 0; i >= 0; i--) {
		sum += flo[i];
		a[i] += sum;
	}
	for (i = 0; i < num; i++)
		ans = max(ans, a[i]);
	cout << ans << "\n";
	return 0;
}