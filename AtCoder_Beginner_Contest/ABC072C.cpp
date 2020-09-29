#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, buf, d[100004] = { 0 }, ans = 0;
	cin >> num;
	for (; i < num; i++) {
		scanf_s("%d", &buf);
		d[buf]++;
		d[buf + 3]--;
	}
	buf = 0;
	for (i = 0; i <= 100000; i++) {
		buf += d[i];
		ans = max(ans, buf);
	}
	cout << ans << "\n";
	return 0;
}