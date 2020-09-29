#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int i = 1, ans = 0;
	string s, n;
	cin >> s;
	n = s[0];
	for (; i < s.size(); i++) {
		if (s[i] != n[0]) {
			ans++;
			n = s[i];
		}
	}
	cout << ans << "\n";
	return 0;
}