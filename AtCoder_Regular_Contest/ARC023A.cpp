#include <iostream>

using namespace std;

int Days(int y, int m, int d) {
	if (m == 1 || m == 2) {
		y--;
		m += 12;
	}
	m++;
	return 365 * y + y / 4 - y / 100 + y / 400 + 306 * m / 10 + d - 429;
}

int main(void) {
	int y, m, d, a, b;
	cin >> y >> m >> d;
	a = Days(2014, 5, 17);
	b = Days(y, m, d);
	printf("%d\n", a - b);
	return 0;
}