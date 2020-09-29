#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b, ans;
	cin >> a >> b;
	ans = max(a + a - 1, b + b - 1);
	ans = max(ans, a + b);
	cout << ans << "\n";
	return 0;
}