#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int st, ed, ans;
	cin >> st >> ed;
	ans = abs(st - ed);
	cout << min(ans, 10 - ans) << "\n";
	return 0;
}