#include <iostream>

using namespace std;

int main(void) {
	int num, d, ans;
	cin >> num >> d;
	d = d + d + 1;
	ans = num / d;
	if (num % d > 0)
		ans++;
	cout << ans << "\n";
	return 0;
}
