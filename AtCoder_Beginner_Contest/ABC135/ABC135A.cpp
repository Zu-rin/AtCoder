#include <iostream>

using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;
	a += b;
	if (a & 1)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", a >> 1);
	return 0;
}