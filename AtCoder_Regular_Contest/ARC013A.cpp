#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M, L, a, b, c, ans;
	scanf_s("%d%d%d%d%d%d", &N, &M, &L, &a, &b, &c);
	ans = max((N / a) * (M / b) * (L / c), (N / a) * (M / c) * (L / b));
	ans = max(ans, (N / b) * (M / a) * (L / c));
	ans = max(ans, (N / b) * (M / c) * (L / a));
	ans = max(ans, (N / c) * (M / a) * (L / b));
	ans = max(ans, (N / c) * (M / b) * (L / a));
	cout << ans << "\n";
	return 0;
}