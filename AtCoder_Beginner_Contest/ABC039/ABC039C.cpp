#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int i = 1, b1 = 0, b2 = 0;
	string s;
	cin >> s;
	while (s[i] == 'B') {
		b1++;
		i += 2;
	}
	i++;
	while (s[i] == 'B') {
		b2++;
		i += 2;
	}
	switch (b1) {
	case 0:
		if (b2 == 2)
			cout << "Si\n";
		else
			cout << "Mi\n";
		break;
	case 1:
		if (b2 == 2)
			cout << "La\n";
		else
			cout << "Re\n";
		break;
	case 2:
		if (b2 == 2)
			cout << "So\n";
		else
			cout << "Do\n";
		break;
	case 3:
		cout << "Fa\n";
	}
	return 0;
}