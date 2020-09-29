#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int i = 0, num, R = 0, B = 0;
	string str;
	cin >> num >> str;
	for (; i < num; i++) {
		if (str[i] == 'R')
			R++;
		else
			B++;
	}
	if (R > B)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}