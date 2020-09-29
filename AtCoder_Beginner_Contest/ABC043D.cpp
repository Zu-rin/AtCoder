#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]) {
			printf("%d %d\n", i + 1, i + 2);
			return 0;
		}
		else if (i < s.size() - 2 && s[i] == s[i + 2]) {
			printf("%d %d\n", i + 1, i + 3);
			return 0;
		}
	}
	printf("-1 -1\n");
	return 0;
}