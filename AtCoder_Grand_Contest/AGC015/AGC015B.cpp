#include <iostream>
#include <string>

using namespace std;

int main(void) {
	long long ans = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'U') {
			ans += s.size() - i - 1;
			ans += i << 1;
		}
		else {
			ans += i;
			ans += (s.size() - i - 1) << 1;
		}
	}
	cout << ans << "\n";
	return 0;
}