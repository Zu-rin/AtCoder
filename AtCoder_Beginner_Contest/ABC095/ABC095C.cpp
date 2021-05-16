#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b, c, x, y, ans;
	scanf_s("%d%d%d%d%d", &a, &b, &c, &x, &y);
	ans = min(a + b, c + c) * min(x, y);
	if (x > y)
		ans += min(a, c + c) * (x - y);
	else if (x < y)
		ans += min(b, c + c) * (y - x);
	printf("%d\n", ans);
	return 0;
}