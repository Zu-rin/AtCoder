#include <iostream>

using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;
	a = abs(a);
	b = abs(b);
	if (a < b)
		printf("Ant\n");
	else if (a > b)
		printf("Bug\n");
	else
		printf("Draw\n");
	return 0;
}