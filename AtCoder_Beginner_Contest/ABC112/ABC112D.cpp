#include <iostream>

using namespace std;

int main(void) {
	int n, m, i;
	cin >> n >> m;
	for (i = m / n; i > 0; i--) {
		if (m % i == 0)
			break;
	}
	printf("%d\n", i);
	return 0;
}