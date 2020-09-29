#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	string s, t;
	cin >> s;
	t = s;
	int a = 0, b = 0, ans = 0, i;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			if (i & 1) {
				s[i] = '2';
				t[i] = '5';
			}
			else {
				s[i] = '5';
				t[i] = '2';
			}
		}
	}
	for (i = 0; i < s.size(); i++) {
		if ((i < s.size() && s[i] == '2' && s[i + 1] == '5') || (i > 0 && s[i - 1] == '2' && s[i] == '5')) {
			a++;
			ans = max(ans, a);
		}
		else
			a = 0;
		if ((i < s.size() && t[i] == '2' && t[i + 1] == '5') || (i > 0 && t[i - 1] == '2' && t[i] == '5')) {
			b++;
			ans = max(ans, b);
		}
		else
			b = 0;
	}
	if (ans & 1)
		ans--;
	cout << ans << "\n";
	return 0;
}