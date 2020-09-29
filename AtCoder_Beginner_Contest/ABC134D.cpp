#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, j, a, m = 0;
	cin >> num;
	vector<int> d(num + 1), ans(num + 1, false);
	for (i = 1; i <= num >> 1; i++)
		scanf_s("%d", &d[i]);
	for (; i <= num; i++) {
		scanf_s("%d", &d[i]);
		ans[i] = d[i];
		if (ans[i])
			m++;
	}
	for (i = num >> 1; i > 0; i--) {
		for (a = 0, j = i << 1; j <= num; j += i) {
			a ^= ans[j];
		}
		if (a != d[i]) {
			ans[i] = true;
			m++;
		}
	}
	printf("%d\n", m);
	for (i = 1; i <= num; i++) {
		if (ans[i])
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}