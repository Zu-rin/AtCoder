#include <iostream>

using namespace std;

int main(void) {
	int n, x, i, a = 1;
	cin >> n >> x;
	if (x == 1 || x == 2 * n - 1)
		printf("No\n");
	else {
		printf("Yes\n");
		for (i = 0; i < n - 2; i++) {
			if (a == x - 1)
				a = x + 2;
			printf("%d\n", a);
			a++;
		}
		printf("%d\n%d\n%d\n", x - 1, x, x + 1);
		for (i = 0; i < n - 2; i++) {
			if (a == x - 1)
				a = x + 2;
			printf("%d\n", a);
			a++;
		}
	}
	return 0;
}