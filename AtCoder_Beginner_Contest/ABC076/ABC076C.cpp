#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int i, j;
	string s, t;
	cin >> s >> t;
	for (i = s.size() - t.size(); i >= 0; i--) {
		for (j = 0; j < t.size(); j++) {
			if (s[i + j] != '?' && s[i + j] != t[j])
				break;
		}
		if (j == t.size())
			break;
	}
	if (i < 0)
		printf("UNRESTORABLE\n");
	else {
		for (j = 0; j < t.size(); j++)
			s[i + j] = t[j];
		for (i = 0; i < s.size(); i++) {
			if (s[i] == '?')
				s[i] = 'a';
		}
		cout << s << "\n";
	}
	return 0;
}