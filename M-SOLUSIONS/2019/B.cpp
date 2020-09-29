#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int n = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'o')
			n++;
	}
	if (n + (15 - s.size()) >= 8)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}