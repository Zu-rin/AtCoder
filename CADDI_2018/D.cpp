#include <iostream>

using namespace std;

int main(void) {
	int num, i, a, w = false;;
	cin >> num;
	for (i = 0; i < num; i++) {
		scanf_s("%d", &a);
		if (a & 1) {
			w = true;
			break;
		}
	}
	if (w)
		printf("first\n");
	else
		printf("second\n");
	return 0;
}