#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string a, s;
	cin >> a >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != a[0])
			printf("%c", s[i]);
	}
	cout << "\n";
	return 0;
}