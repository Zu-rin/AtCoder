#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	int ans = 0, a = 0, b = 0, i;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == '2')
			a++;
		else
			b++;
		if (b > a) {
			ans = -1;
			break;
		}
		ans = max(ans, a - b);
	}
	if (a != b)
		ans = -1;
	cout << ans << "\n";
	return 0;	
}