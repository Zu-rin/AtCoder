#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int num, k, i, ans = 0, p = 0;
	string s;
	cin >> num >> k >> s;
	for (i = 1; i < num; i++) {
		if (s[i - 1] == s[i])
			ans++;
		else if (s[i] != s[0])
			p++;
	}
	ans += min(p, k) << 1;
	if (s[0] != s[num - 1] && p <= k)
		ans--;
	cout << ans << "\n";
	return 0;
}