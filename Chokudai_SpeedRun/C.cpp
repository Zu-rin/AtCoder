#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, a, b, i = 0, ans = 0;
	cin >> num;
	for (; i < num; i++) {
		scanf("%d%d", &a, &b);
		ans = max(ans, a + b);
	}
	printf("%d\n", ans);
	return 0;
}