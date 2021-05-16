#include <iostream>

using namespace std;

int main(void) {
	int n, ans = 0;
	cin >> n;
	while (n > 0) {
		ans += n % 10;
		n /= 10;
	}
	if (ans == 1)
		printf("10\n");
	else
		printf("%d\n", ans);
	return 0;
}