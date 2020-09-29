#include <iostream>

using namespace std;

int main(void) {
	char c;
	cin >> c;
	if (c == 'A')
		cout << 'T';
	else if (c == 'T')
		cout << 'A';
	else if (c == 'C')
		cout << 'G';
	else if (c == 'G')
		cout << 'C';
	return 0;
}