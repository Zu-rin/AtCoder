#include <iostream>
#include <algorithm>

using namespace std;

void gcd(int a, int b) {
	if (b == 0) {
		printf("%d\n", a);
		return;
	}
	if (a >= b)
		gcd(b, a % b);
	else
		gcd(a, b % a);
	return;
}

int main(void) {
	int num, a, b, i = 0;
	long long ans = 0;
	cin >> num;
	for (; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		gcd(a, b);
	}
	return 0;
}