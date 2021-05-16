#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	int num, i, a = 0, b = 0;
	cin >> num >> s;
	for (i = 0; i < num; i++) {
		if (s[i] == '(')
			b++;
		else if (b > 0)
			b--;
	}
	for (i = num - 1; i >= 0; i--) {
		if (s[i] == ')')
			a++;
		else if (a > 0)
			a--;
	}
	for (i = 0; i < a; i++)
		printf("(");
	cout << s;
	for (i = 0; i < b; i++)
		printf(")");
	cout << "\n";
	return 0;
}