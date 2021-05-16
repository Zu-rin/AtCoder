#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, x, a, n = 0, ans = 0, i;
	cin  >> num >> x;
	for (i = 0; i < num; i++) {
		scanf_s("%d", &a);
		n += a;
		ans++;
		if (n > x)
			break;
	}
	if (n <= x)
		ans++;
	printf("%d\n", ans);
	return 0;
}