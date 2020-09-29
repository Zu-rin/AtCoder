#include <iostream>

using namespace std;

int main(void) {
	int n, i, a;
	cin >> n;
	for (i = 1; i <= n; i++) {
		a = true;
		if (i % 2 == 0) {
			printf("a");
			a = false;
		}
		if (i % 3 == 0) {
			printf("b");
			a = false;
		}
		if (i % 4 == 0) {
			printf("c");
			a = false;
		}
		if (i % 5 == 0) {
			printf("d");
			a = false;
		}
		if (i % 6 == 0) {
			printf("e");
			a = false;
		}
		if (a)
			printf("%d", i);
		printf("\n");
	}
	return 0;
}