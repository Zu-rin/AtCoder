#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o')
			continue;
		printf("%c", s[i]);
	}
	cout << "\n";
	return 0;
}