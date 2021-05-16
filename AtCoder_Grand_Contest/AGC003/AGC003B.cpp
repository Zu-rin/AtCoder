#include <iostream>

using namespace std;

int main(void) {
	int num, i, a, c = 0;
	long long ans = 0;
	cin >> num;
	for (i = 0; i < num; i++) {
		scanf_s("%d", &a);
		if (c == 1 && a > 0) {
			a--;
			ans++;
		}
		ans += a >> 1;
		if (a & 1)
			c = 1;
		else
			c = 0;
	}
	cout << ans << "\n";
	return 0;
}