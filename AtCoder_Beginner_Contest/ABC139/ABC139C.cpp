#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a = 0, x, y, ans = 0;
	cin >> num >> x;
	for (i = 0; i < num - 1; i++) {
		cin >> y;
		if (x >= y)
			a++;
		else
			a = 0;
		ans = max(a, ans);
		x = y;
	}
	cout << ans << "\n";
	return 0;
}