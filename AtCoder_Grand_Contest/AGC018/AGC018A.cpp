#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	int num, k, i, g, ma, a;
	cin >> num >> k >> g;
	ma = g;
	for (i = 0; i < num - 1; i++) {
		scanf_s("%d", &a);
		g = gcd(a, g);
		ma = max(ma, a);
	}
	if (k > ma || k % g != 0)
		printf("IMPOSSIBLE\n");
	else
		printf("POSSIBLE\n");
	return 0;
}