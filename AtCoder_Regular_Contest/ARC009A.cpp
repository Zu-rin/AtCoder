#include <iostream>

using namespace std;

int main(void) {
	double n = 0.0;
	int a, b, num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		scanf("%d%d", &a, &b);
		n += a * b;
	}
	printf("%d\n", (int)(n * 1.05));
	return 0;
}