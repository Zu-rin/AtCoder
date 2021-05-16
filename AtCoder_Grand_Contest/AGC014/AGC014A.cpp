#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int a[3] = { 0 }, n[3], i;
	for (i = 0; i < 3; i++)
		cin >> n[i];
	if (n[0] == n[1] && n[1] == n[2]) {
		if (n[0] & 1)
			printf("0\n");
		else
			printf("-1\n");
	}
	else {
		for (i = 0; i < 3; i++) {
			while ((n[i] & 1) == 0) {
				a[i]++;
				n[i] >>= 1;
			}
		}
		i = min(min(a[0], a[1]), a[2]);
		if (a[0] == a[1] && a[1] == a[2])
			i++;
		printf("%d\n", i);
	}
	return 0;
}