#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int i = 0, pos;
	string s, t, at = "atcoder";
	cin >> s >> t;
	for (; i < s.size(); i++) {
		if (s[i] == t[i])
			continue;
		if (s[i] == '@') {
			pos = at.find(t[i]);
			if (pos != string::npos)
				continue;
		}
		else if (t[i] == '@') {
			pos = at.find(s[i]);
			if (pos != string::npos)
				continue;
		}
		break;
	}
	if (i == s.size())
		printf("You can win\n");
	else
		printf("You will lose\n");
	return 0;
}