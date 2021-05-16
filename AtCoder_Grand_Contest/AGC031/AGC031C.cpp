#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int num, alpha, beta, max, anum = 0, bnum = 0, i = 0;
	cin >> num;
	cin >> alpha;
	cin >> beta;
	max = 1 << num - 1;
	if (alpha < 1 || alpha > max || beta < 1 || beta > max) {
		printf("NO");
		return 0;
	}
	while (alpha == 0 && beta == 0) {
		if (alpha & 1)
			anum++;
		if (beta & 1)
			bnum++;
		alpha >>= 1;
		beta >>= 1;
	}


	return 0;
}