#include <iostream>

using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;
	if (a >= 13)
		printf("%d\n", b);
	else if(a > 5)
		printf("%d\n", b >> 1);
	else
		printf("0\n");
	return 0;
}