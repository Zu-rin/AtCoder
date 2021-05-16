#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, ans, a, b;
	cin >> num >> a;
	ans = a;
	for (i = 0; i < num - 2; i++) {
		cin >> b;
		ans += min(a, b);
		a = b;
	}
	ans += a;
	cout << ans << "\n";
	return 0;
}