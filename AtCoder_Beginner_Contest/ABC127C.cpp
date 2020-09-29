#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int i = 0, l, r, L = 0, R = 100000, c, g;
	cin >> c >> g;
	for (; i < g; i++) {
		scanf_s("%d%d", &l, &r);
		L = max(L, l);
		R = min(R, r);
	}
	R = R - L + 1;
	if (R <= 0)
		printf("0\n");
	else
		printf("%d\n", R);
	return 0;
}