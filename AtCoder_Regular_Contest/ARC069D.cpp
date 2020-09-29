#include <iostream>
#include <string>

using namespace std;

int Judge(const string s, string &ans, string c) {
	for (int i = 1; i < s.size(); i++) {
		if (ans[i] == 'S') {
			if (s[i] == 'o')
				ans += ans[i - 1];
			else {
				if (ans[i - 1] == 'S')
					ans += "W";
				else
					ans += "S";
			}
		}
		else {
			if (s[i] == 'x')
				ans += ans[i - 1];
			else {
				if (ans[i - 1] == 'S')
					ans += "W";
				else
					ans += "S";
			}
		}
	}
	if (ans[0] == ans[s.size()] && ans[s.size() - 1] == c[0]) {
		ans[s.size()] = '\n';
		return true;
	}
	return false;
}

int main(void) {
	string s, ans;
	int num, i;
	cin >> num >> s;
	if (s[0] == 'o') {
		if (Judge(s, ans = "WS", "W") || Judge(s, ans = "SW", "W") || Judge(s, ans = "WW", "S") || Judge(s, ans = "SS", "S"))
			cout << ans;
		else
			printf("-1\n");
	}
	else {
		if (Judge(s, ans = "WS", "S") || Judge(s, ans = "SW", "S") || Judge(s, ans = "WW", "W") || Judge(s, ans = "SS", "W"))
			cout << ans;
		else
			printf("-1\n");
	}
	return 0;
}