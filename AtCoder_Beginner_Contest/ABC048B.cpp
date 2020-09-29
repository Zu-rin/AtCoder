#include <iostream>

using namespace std;

int main(void) {
	long long a, b, x;
	cin >> a >> b >> x;
	if (a == 0)
		cout << b / x + 1 << "\n";
	else
		cout << (b / x) - ((a - 1) / x) << "\n";
	return 0;
}