#include <iostream>

using namespace std;

int main(void) {
	long long s, c;
	cin >> s >> c;
	if (s * 2 > c) {
		cout << c / 2 << "\n";
		return 0;
	}
	c -= s * 2;
	cout << c / 4 + s << "\n";
	return 0;
}