#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int num, i, j;
	string s, t;
	cin >> num >> s >> t;
	for (i = 0; i < num; i++) {
		for (j = 0; i + j < num; j++) {
			if (s[i + j] != t[j])
				break;
		}
		if (j == num - i)
			break;
	}
	cout << i + num << "\n";
	return 0;
}