#include <iostream>

using namespace std;

int main(void) {
	int n, a = 0, i;
	cin >> n;
	while (n > 0) {
		a++;
		n -= a;
	}
	n *= -1;
	for (i = 1; i < n; i++)
		printf("%d\n", i);
	for (i = n + 1; i <= a; i++)
		printf("%d\n", i);
	return 0;
}