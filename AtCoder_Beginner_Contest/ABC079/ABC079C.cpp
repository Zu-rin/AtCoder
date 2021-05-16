#include <iostream>

using namespace std;

int main(void) {
	int a, b, c, d;
	cin >> a;
	d = a % 10;
	a /= 10;
	c = a % 10;
	a /= 10;
	b = a % 10;
	a /= 10;
	if (a + b + c + d == 7)
		printf("%d+%d+%d+%d=7", a, b, c, d);
	else if (a + b + c - d == 7)
		printf("%d+%d+%d-%d=7", a, b, c, d);
	else if (a + b - c + d == 7)
		printf("%d+%d-%d+%d=7", a, b, c, d);
	else if (a + b - c - d == 7)
		printf("%d+%d-%d-%d=7", a, b, c, d);
	else if (a - b + c + d == 7)
		printf("%d-%d+%d+%d=7", a, b, c, d);
	else if (a - b + c - d == 7)
		printf("%d-%d+%d-%d=7", a, b, c, d);
	else if (a - b - c + d == 7)
		printf("%d-%d-%d+%d=7", a, b, c, d);
	else if (a - b - c - d == 7)
		printf("%d-%d-%d-%d=7", a, b, c, d);
	return 0;
}