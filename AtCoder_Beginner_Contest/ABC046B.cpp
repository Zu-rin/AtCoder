#include <iostream>

using namespace std;

int main(void) {
	int n, k, ans;
	cin >> n >> k;
	ans = k--;
	while (n > 1) {
		ans *= k;
		n--;
	}
	printf("%d\n", ans);
	return 0;
}