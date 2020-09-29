#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	int l = 0, r = s.size() - 1, ans = 0;
	while (l < r) {
		if (s[l] == s[r]) {
			l++;
			r--;
		}
		else if (s[l] == 'x') {
			ans++;
			l++;
		}
		else if (s[r] == 'x') {
			ans++;
			r--;
		}
		else {
			ans = -1;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}