#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	long long a, b, k, l, ans;
	cin >> a >> b >> k >> l;
	ans = b * (k / l);
	k %= l;
	ans += min(a * k, b);
	cout << ans << "\n";
	return 0;
}