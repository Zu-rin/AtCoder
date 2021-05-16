#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int i, j = 0;
	long long ans = 0;
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == 'W') {
			ans += i - j;
			j++;
		}
	}
	cout << ans << "\n";
	return 0;
}