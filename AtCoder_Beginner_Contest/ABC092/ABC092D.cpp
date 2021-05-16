#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b, i, j;
	vector<string> s(100);
	cin >> a >> b;
	cout << "100 100\n";
	for (i = 0; i < 100; i++) {
		s[0] += "#";
		s[50] += ".";
	}
	for (i = 1; i < 50; i++)
		s[i] = s[0];
	for (i = 51; i < 100; i++)
		s[i] = s[50];
	j = 0;
	while (a > 1) {
		for (i = 0; i < 100 && a > 1; i += 2) {
			a--;
			s[j][i] = '.';
		}
		j += 2;
	}
	j = 99;
	while (b > 1) {
		for (i = 0; i < 100 && b > 1; i += 2) {
			b--;
			s[j][i] = '#';
		}
		j -= 2;
	}
	for (i = 0; i < 100; i++)
		cout << s[i] << "\n";
	return 0;
}