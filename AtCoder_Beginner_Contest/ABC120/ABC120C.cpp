#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int i, a = 0, b = 0;
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			a++;
		else
			b++;
	}
	printf("%d", min(a, b) << 1);
	return 0;
}