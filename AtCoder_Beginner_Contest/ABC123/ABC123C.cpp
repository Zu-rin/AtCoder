#include <iostream>

using namespace std;

int main(void) {
	int i = 0, min = 0;
	long long num, a[5], ans = 4;
	cin >> num;
	for (; i < 5; i++) {
		cin >> a[i];
		if (a[i] <= a[min])
			min = i;
	}
	if (num % a[min] > 0)
		ans++;
	ans += num / a[min];
	cout << ans << "\n";
	return 0;
}