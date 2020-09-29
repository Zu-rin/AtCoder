#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int i = 0, n, ans = 999;
	string s;
	cin >> s;
	for (; i < s.size() - 2; i++) {
		n = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
		ans = min(ans, abs(n - 753));
	}
	printf("%d\n", ans);
	return 0;
}