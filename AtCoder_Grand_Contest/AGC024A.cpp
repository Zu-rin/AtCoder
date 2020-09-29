#include <iostream>

using namespace std;

int main(void) {
	long long a, b, c;
	cin >> a >> b >> c >> c;
	if (c & 1)
		cout << b - a << "\n";
	else
		cout << a - b << "\n";
	return 0;
}