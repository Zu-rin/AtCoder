#include <iostream>

using namespace std;

int main(void) {
	int num, i, j, k;
	cin >> num;
	k = num;
	if (!(num & 1)) {
		k++;
		printf("%d\n", num * (num - 2) / 2);
	}
	else
		printf("%d\n", (num - 1) * (num - 1) / 2);
	for (i = 1; i <= num; i++) {
		for (j = i + 1; j <= num; j++) {
			if (j != k - i)
				printf("%d %d\n", i, j);
		}
	}
	return 0;
}