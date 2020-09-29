#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int i, a = 0, ans = 1;
	string s;
	cin >> s;
	for (i = 1; i < s.size(); i++) {
		if (s[i] <= s[a]) {
			a = i;
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}