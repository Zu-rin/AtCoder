#include <iostream>
#include <vector>
#define MAX 55556

using namespace std;

int main(void) {
	int num, i, j;
	vector<int> d(MAX, true);
	cin >> num;
	for (i = 2; i < MAX - 1; i++) {
		if (d[i]) {
			for (j = i << 1; j < MAX; j += i) {
				d[j] = false;
			}
		}
	}
	printf("2 ");
	j = 1;
	for (i = 3; i < MAX; i++) {
		if (j == num)
			break;
		if (d[i] && i % 5 == 1) {
			printf("%d ", i);
			j++;
		}
	}
	printf("\n");
	return 0;
}