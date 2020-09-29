#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	long long a, b, c, ans;
	cin >> a >> b >> c;
	if (!(a & 1) || !(b & 1) || !(c & 1)) {
		printf("0\n");
		return 0;
	}
	ans = min(a * b, b * c);
	ans = min(ans, a * c);
	cout << ans << "\n";
	return 0;
}