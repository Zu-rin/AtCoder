#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int i, j, l;
	string s, abc = "abcdefghijklmnopqrstuvwxyz";
	cin >> s;
	l = s.size();
	if (l == 26) {
		vector<int> d(26, false);
		d[s[s.size() - 1] - 'a'] = true;
		for (i = l - 2; i >= 0; i--) {
			if (s[i] < s[i + 1])
				break;
			d[s[i] - 'a'] = true;
		}
		if (i < 0)
			printf("-1");
		else {
			for (j = s[i] - 'a' + 1; j < 26; j++) {
				if (d[j]) {
					s[i] = abc[j];
					break;
				}
			}
			for (j = 0; j <= i; j++)
				cout << s[j];
		}
	}
	else {
		vector<int> d(26, true);
		for (i = 0; i < l; i++)
			d[s[i] - 'a'] = false;
		cout << s;
		for (i = 0; i < 26; i++) {
			if (d[i]){
				cout << abc[i];
				break;
			}
		}
	}
	printf("\n");
	return 0;
}