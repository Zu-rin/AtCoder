#include <stdio.h>
#include <iostream>

#define ALLSUM 2025

using namespace std;

int main(void) {
	int x, a, i = 1;
	cin >> x;
	x = ALLSUM - x;
	for (; i < 10; i++) {
		a = x / i;
		if (x % i == 0 && a < 10)
			cout << i << " x " << a << "\n";
	}
	return 0;
}