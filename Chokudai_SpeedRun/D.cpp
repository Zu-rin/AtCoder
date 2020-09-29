#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, a, b, i = 0;
	long long ans = 0;
	cin >> num;
	for (; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		ans += max(a, b);
	}
	printf("%ld\n", ans);
	return 0;
}