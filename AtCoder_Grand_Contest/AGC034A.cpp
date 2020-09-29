#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int num, s1, s2, g1, g2, i;
	string s;
	cin >> num >> s1 >> s2 >> g1 >> g2 >> s;
	s1--; s2--;
	g1--; g2--;
	for(i = s1; i < max(g1, g2); i++){
		if (s[i] == '#' && s[i + 1] == '#') {
			printf("No\n");
			return 0;
		}
	}
	if (g1 > g2) {
		for (i = s2 - 1; i < g2; i++) {
			if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.')
				break;
		}
		if (i == g2) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}