#include <stdio.h>

using namespace std;

int main(void) {
	int n, m;
	scanf_s("%d%d", &n, &m);
	n = 1800 * m + 100 * n;
	n <<= m;
	printf("%d\n", n);
	return 0;
}