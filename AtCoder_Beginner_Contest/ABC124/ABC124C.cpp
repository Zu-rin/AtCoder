#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int i = 0, a0 = 0, a1 = 0;
	bool cl = true;
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i+=2) {
		if (s[i] == '1')
			a0++;
		else
			a1++;
	}
	for (i = 1; i < s.size(); i += 2) {
		if (s[i] == '0')
			a0++;
		else
			a1++;
	}
	cout << min(a0, a1) << "\n";
	return 0;
}