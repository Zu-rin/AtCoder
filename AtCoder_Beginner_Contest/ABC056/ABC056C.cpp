#include <iostream>

using namespace std;

int main(void) {
	int x, i = 0;
	cin >> x;
	while (x > 0)
		x -= ++i;
	cout << i << "\n";
	return 0;
}