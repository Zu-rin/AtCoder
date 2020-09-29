#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	int len, k;
	cin >> len >> k >> s;
	s[k - 1] = s[k - 1] - 'A' + 'a';
	cout << s << endl;
	return 0;
}