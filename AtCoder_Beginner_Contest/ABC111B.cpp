#include <iostream>

using namespace std;

int main(void) {
	int n, a;
	cin >> n;
	a = (n / 100) * 111;
	if (n <= a)
		printf("%d\n", a);
	else
		printf("%d\n", a + 111);
	return 0;
}