#include <iostream>

using namespace std;

int main(void) {
	int R, G, B, num, ans = 0, i;
	scanf_s("%d%d%d%d", &R, &G, &B, &num);
	for (; num >= 0; num -= R) {
		for (i = num; i >= 0; i -= G) {
			if (i % B == 0)
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}