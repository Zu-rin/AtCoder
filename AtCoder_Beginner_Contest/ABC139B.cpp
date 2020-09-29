#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int a, b, i, ans = 0;
	cin >> a >> b;
	for (i = 1; i < b; i += a - 1) {
		ans++;
	}
	cout << ans << "\n";
	return 0;
}