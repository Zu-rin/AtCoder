#include <iostream>

using namespace std;

void Search(int n) {
	if (n == 0)
		return;
	int a = n % 2;
	if (a == 0) {
		Search(n / -2);
		printf("0");
	}
	else {
		Search((n - 1) / -2);
		printf("1");
	}
	return;
}

int main(void) {
	int n;
	cin >> n;
	if (n == 0)
		printf("0\n");
	else
		Search(n);
	return 0;
}