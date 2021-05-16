#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	int i, j;
	string b;
	vector<string> s(4, "aaaa");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			cin >> b;
			s[i][j] = b[0];
		}
	}
	for (int i = 3; i >= 0; i--) {
		for (int j = 3; j >= 0; j--) {
			printf("%c", s[i][j]);
			if (j != 0)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}