#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int k, i;
	string s;
	cin >> s >> k;
	for (i = 0; i < s.size() - 1; i++) {
		if (s[i] != 'a' && k >= 'z' - s[i] + 1) {
			k -= 'z' - s[i] + 1;
			s[i] = 'a';
		}
	}
	k %= 26;
	if (s[i] + k > 'z') {
		k -= 'z' - s[i] + 1;
		s[i] = 'a' + k;
	}
	else
		s[i] += k;
	cout << s << "\n";
	return 0;
}