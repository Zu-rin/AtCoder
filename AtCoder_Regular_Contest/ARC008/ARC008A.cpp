#include <iostream>

using namespace std;

int main(void) {
	int a, b;
	cin >> a;
	b = a % 10;
	a /= 10;
	if (b > 6)
		cout << 100 * (a + 1) << "\n";
	else
		cout << 100 * a + 15 * b << "\n";
	return 0;
}