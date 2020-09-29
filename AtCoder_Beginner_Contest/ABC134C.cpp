#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, a, ma1 = 0, ma2 = 0, id = 0;
	cin >> num;
	for (i = 0; i < num; i++) {
		scanf_s("%d", &a);
		if (ma1 <= a) {
			id = i;
			ma2 = ma1;
			ma1 = a;
		}
		else if (ma2 <= a)
			ma2 = a;
	}
	for (i = 0; i < num; i++) {
		if (i == id)
			printf("%d\n", ma2);
		else
			printf("%d\n", ma1);
	}
	return 0;
}