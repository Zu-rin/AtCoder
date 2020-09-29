#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int i, ans = 100, sum, cnt;
	string s;
	cin >> s;
	for (char c = 'a'; c <= 'z'; c++) {
		sum = 0;
		cnt = 0;
		for (i = 0; i < s.size(); i++) {
			if (s[i] == c)
				cnt = 0;
			else {
				cnt++;
				sum = max(sum, cnt);
			}
		}
		ans = min(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}