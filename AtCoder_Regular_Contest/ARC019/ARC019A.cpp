#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int p;
	string s, a = "OIZ34S67B9", b = "D123456789";
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			printf("0");
		else {
			p = a.find(s[i]);
			if (p != -1)
				printf("%d", p);
			else {
				p = b.find(s[i]);
				printf("%d", p);
			}
		}
	}
	printf("\n");
	return 0;
}