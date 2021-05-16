#include <iostream>

using namespace std;

int main(void) {
	int num, k, all, i, j;
	cin >> num >> k;
	all = (num - 1) * (num - 2) / 2;
	if (k > all) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", num - 1 + all - k);
	for (i = 2; i <= num; i++)
		printf("1 %d\n", i);
	for (i = 2; i < num; i++) {
		if (all == k)
			break;
		for (j = i + 1; j <= num; j++) {
			printf("%d %d\n", i, j);
			all--;
			if (all == k)
				break;
		}
	}
	return 0;
}