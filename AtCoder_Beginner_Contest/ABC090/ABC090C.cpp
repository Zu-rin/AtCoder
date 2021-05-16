#include <iostream>

using namespace std;

int main(void) {
	long long a, b;
	cin >> a >> b;
	if (a == 1)
		a = 3;
	if (b == 1)
		b = 3;
	cout << (a - 2)*(b - 2) << "\n";
	return 0;
}