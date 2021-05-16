#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	int a;
	cin >> a >> s;
	if (a >= 3200)
		cout << s << "\n";
	else
		cout << "red\n";
	return 0;
}