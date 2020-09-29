#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	if (b / a >= c)
		cout << c << "\n";
	else
		cout << b / a << "\n";
	return 0;
}