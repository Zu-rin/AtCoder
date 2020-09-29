#include <iostream>

using namespace std;

int main(void) {
	int n, a, b;
	cin >> n >> a >> b;
	a = abs(a - b);
	if (a & 1)
		printf("Borys\n");
	else
		printf("Alice\n");
	return 0;
}