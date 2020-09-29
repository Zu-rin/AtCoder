#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	c -= a - b;
	if (c < 0)
		printf("0\n");
	else
		printf("%d\n", c);
	return 0;
}