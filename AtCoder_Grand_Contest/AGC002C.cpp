#include <iostream>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, ans = 0, k;
	ll a, b;
	cin >> num >> k >> a;
	for (i = 1; i < num; i++) {
		scanf_s("%lld", &b);
		if (a + b >= k) {
			ans = i;
			break;
		}
		a = b;
	}
	if (ans == 0) {
		printf("Impossible\n");
	}
	else {
		printf("Possible\n");
		for (i = 1; i < ans; i++)
			printf("%d\n", i);
		for (i = num - 1; i >= ans; i--)
			printf("%d\n", i);
	}
	return 0;
}