#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	int num, i, j, a, ok, ans = 0;
	cin >> num;
	vector<string> s(num);
	for (i = 0; i < num; i++) {
		cin >> s[i];
		s[i] += s[i];
	}
	for (a = 0; a < num; a++) {
		ok = true;
		for (i = 0; i < num; i++) {
			for (j = i + 1; j < num; j++) {
				if (s[i][j + a] != s[j][i + a]) {
					ok = false;
					break;
				}
			}
		}
		if (ok)
			ans++;
	}
	cout << ans * num << "\n";
	return 0;
}