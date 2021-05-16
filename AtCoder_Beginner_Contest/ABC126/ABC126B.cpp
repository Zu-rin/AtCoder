#include <iostream>

using namespace std;

int main(void) {
	int k;
	cin >> k;
	if (k / 100 == 0 || k / 100 > 12) {
		if (k % 100 == 0 || k % 100 > 12)
			printf("NA\n");
		else
			printf("YYMM\n");
	}
	else {
		if (k % 100 == 0 || k % 100 > 12)
			printf("MMYY\n");
		else
			printf("AMBIGUOUS\n");
	}
	return 0;
}