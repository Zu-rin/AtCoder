#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int main(void) {
	int i, a = 1, ans = 1;
	string s, buf, x;
	cin >> s;
	buf = s.substr(0, 1);
	for (i = 2; i <= s.size(); i++) {
		if (buf != s.substr(a, i - a)) {
			buf = s.substr(a, i - a);
			ans++;
			a = i;
		}
	}
	cout << ans << "\n";
	return 0;
}