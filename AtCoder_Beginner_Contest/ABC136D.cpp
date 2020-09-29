#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	int i, a;
	vector<int> d(s.size(), 0);
	for (i = 0; i < s.size(); i++) {
		if (s[i] == 'L') {
			a = i;
			while (i < s.size() && s[i] == 'L') {
				if ((i - a) & 1)
					d[a - 1]++;
				else
					d[a]++;
				i++;
			}
		}
	}
	for (i = s.size() - 1; i >= 0; i--) {
		if (s[i] == 'R') {
			a = i;
			while (i >= 0 && s[i] == 'R') {
				if ((a - i) & 1)
					d[a + 1]++;
				else
					d[a]++;
				i--;
			}
		}
	}
	for (i = 0; i < s.size(); i++)
		printf("%d ", d[i]);
	printf("\n");
	return 0;
}