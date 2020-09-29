#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	int num, a, b, i;
	cin >> num >> a >> b >> s;
	a += b;
	for (i = 0; i < num; i++) {
		if (s[i] == 'a') {
			if (a > 0) {
				a--;
				printf("Yes\n");
				continue;
			}
		}
		else if (s[i] == 'b') {
			if (a > 0 && b > 0) {
				a--;
				b--;
				printf("Yes\n");
				continue;
			}
		}
		printf("No\n");
	}
	return 0;
}