#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int i = 1, k = 0, ans = 0;
	string s;
	cin >> s;
	s += '+';
	for (; i < s.size(); i += 2) {
		if (s[i] == '+') {
			for (; k < i; k += 2) {
				if (s[k] == '0')
					break;
			}
			if (k < i)
				k = i + 1;
			else
				ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}