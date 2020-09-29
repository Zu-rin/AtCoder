#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, j, ans[26] = { 0 };
	string s;
	cin >> num >> s;
	for (i = 0; i < s.size(); i++)
		ans[s[i] - 'a']++;
	for (i = 1; i < num; i++) {
		cin >> s;
		vector<int> buf(26, 0);
		for (j = 0; j < s.size(); j++)
			buf[s[j] - 'a']++;
		for (j = 0; j < 26; j++)
			ans[j] = min(ans[j], buf[j]);
	}
	for (i = 0; i < 26; i++) {
		for (j = 0; j < ans[i]; j++)
			printf("%c", i + 'a');
	}
	return 0;
}