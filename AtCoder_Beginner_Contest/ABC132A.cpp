#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int i, ok = true;
	vector<int> d(26, 0);
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i++)
		d[s[i] - 'A']++;
	for (i = 0; i < 26; i++) {
		if (d[i] != 0 && d[i] != 2) {
			ok = false;
			break;
		}
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}