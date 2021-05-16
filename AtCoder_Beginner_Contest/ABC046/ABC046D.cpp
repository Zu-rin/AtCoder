#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int ans = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'g')
			ans++;
		else
			ans--;
	}
	cout << (ans >> 1) << "\n";
	return 0;
}