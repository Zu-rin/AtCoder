#include <iostream>

using namespace std;

int main(void) {
	int num, a, b, i = 0, ans;
	cin >> num;
	for (; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		ans = abs(a - b);
		if (ans == 0)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}