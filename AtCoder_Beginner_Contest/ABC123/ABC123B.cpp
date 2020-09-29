#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int k[6], a[5] = { 0 }, i = 0, ans = 0, num = 5;
	for (; i < 5; i++) {
		cin >> k[i];
		if (k[i] % 10 == 0)
			a[i] = 1;
		else {
			if (num == 5)
				num = i;
			else if (k[num] % 10 > k[i] % 10)
				num = i;
		}
	}
	for (i = 0; i < 5; i++) {
		if (a[i] == 1)
			ans += k[i] / 10;
	}
	for (i = 0; i < 5; i++) {
		if (i == num)
			continue;
		if (a[i] == 0) {
			ans++;
			ans += k[i] / 10;
		}
	}
	k[5] = 0;
	ans *= 10;
	ans += k[num];
	cout << ans << "\n";
	return 0;
}