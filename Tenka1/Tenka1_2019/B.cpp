#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int len, i = 0, k;
	string s;
	cin >> len >> s >> k;
	k--;
	for (; i < len; i++) {
		if (s[i] == s[k])
			cout << s[i];
		else
			cout << "*";
	}
	return 0;
}