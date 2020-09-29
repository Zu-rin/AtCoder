#include <iostream>

using namespace std;

int main(void) {
	int ans = 0;
	long long a, b;
	cin >> a >> b;
	while (a <= b) {
		ans++;
		b >>= 1;
	}
	cout << ans << "\n";
	return 0;
}