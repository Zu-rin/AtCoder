#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, t, ans = 1e9;
	cin >> num;
	while (num-- > 0) {
		scanf_s("%d", &t);
		ans = min(ans, t);
	}
	printf("%d\n", ans);
	return 0;
}