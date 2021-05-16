#include <iostream>

using namespace std;

int main(void) {
	int num, day, a, b, c;
	scanf_s("%d%d%d%d", &num, &day, &a, &b);
	for (int i = 0; i < day; i++) {
		if (num <= a)
			num += b;
		scanf_s("%d", &c);
		num -= c;
		if (num < 0) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("complete\n");
	return 0;
}