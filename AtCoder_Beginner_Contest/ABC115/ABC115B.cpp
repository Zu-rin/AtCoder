#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, a, sum = 0, ma = 0, i = 0;
	cin >> num;
	for (; i < num; i++) {
		scanf_s("%d", &a);
		sum += a;
		ma = max(ma, a);
	}
	printf("%d\n", sum - (ma / 2));
	return 0;
}