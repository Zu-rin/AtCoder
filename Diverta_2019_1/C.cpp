#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, j, a = 0, b = 0, ab = 0, ans = 0, buf;
	string s;
	cin >> num;
	for (; i < num; i++) {
		cin >> s;
		for (j = 0; j < s.size() - 1; j++) {
			if (s[j] == 'A' && s[j + 1] == 'B')
				ans++;
		}
		if (s[0] == 'B') {
			b++;
			if (s[s.size() - 1] == 'A') {
				a++;
				ab++;
			}
		}
		else if (s[s.size() - 1] == 'A')
			a++;
	}
	buf = min(a, b);
	if (buf > 0 && a == b && a == ab)
		buf--;
	printf("%d\n", ans + buf);
	return 0;
}