#include <iostream>

using namespace std;

int main(void) {
	int num, i, a, ans = 0;
	cin >> num;
	for (i = 1; i <= num; i++) {
		scanf_s("%d", &a);
		if (a == i) {
			ans++;
			if (i < num) {
				scanf_s("%d", &a);
				i++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}