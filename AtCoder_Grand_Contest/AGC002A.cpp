#include <iostream>

using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;
	if (a > 0)
		printf("Positive\n");
	else if (b >= 0)
		printf("Zero\n");
	else {
		b -= a;
		if (b & 1)
			printf("Positive\n");
		else
			printf("Negative\n");
	}
	return 0;
}