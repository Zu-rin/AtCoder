#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	int y, m, d;
	cin >> s;
	y = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
	m = (s[5] - '0') * 10 + (s[6] - '0');
	d = (s[8] - '0') * 10 + (s[9] - '0');
	if (y > 2019)
		printf("TBD\n");
	else if (y == 2019) {
		if (m > 4)
			printf("TBD\n");
		else if (m == 4 && d > 30)
			printf("TBD\n");
		else
			printf("Heisei\n");
	}
	else
		printf("Heisei\n");
	return 0;
}