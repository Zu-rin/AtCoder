#include <iostream>

using namespace std;

int main(void) {
	long long num, a, b;
	cin >> num >> a >> b;
	if (num == 1) {
		if (a != b)
			printf("0\n");
		else
			printf("1\n");
	}
	else if (a > b)
		printf("0\n");
	else
		cout << (b - a) * (num - 2) + 1 << "\n";
	return 0;
}