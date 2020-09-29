#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int i, ans = 0;
	string s, t;
	cin >> s >> t;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == t[i])
			ans++;
	}
	cout << ans << "\n";
	return 0;
}