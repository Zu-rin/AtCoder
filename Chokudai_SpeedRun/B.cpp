#include <iostream>

using namespace std;

int main(void) {
	long long num, a, b, i = 0;
	cin >> num;
	for (; i < num; i++) {
		cin >> a >> b;
		cout << a % b << "\n";
	}
	return 0;
}