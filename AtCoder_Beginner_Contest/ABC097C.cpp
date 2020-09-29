#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	int k, i = 0, len = 1, j;
	string s = "aaa", t, buf;
	cin >> s >> k;
	vector<string> ans(k, "zzzzz");
	for (; len <= k; len++) {
		for (j = 0; j <= (int)s.size() - len; j++) {
			t = s.substr(j, len);
			for (i = 0; i < k; i++) {
				if (ans[i].compare(t) > 0) {
					buf = ans[i];
					ans[i] = t;
					t = buf;
				}
				else if (ans[i] == t)
					break;
			}
		}
	}
	cout << ans[k - 1] << "\n";
	return 0;
}