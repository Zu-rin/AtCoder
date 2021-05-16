#include <iostream>

using namespace std;

int main(void) {
	int num, buf, i = 0, ans = 0;
	cin >> num;
	for (; i < num; i++) {
		scanf_s("%d", &buf);
		while ((buf & 1) == 0) {
			ans++;
			buf >>= 1;
		}
	}
	cout << ans << "\n";
	return 0;
}