#include <iostream>

using namespace std;

int main(void) {
	int num, k;
	cin >> num >> k;
	num--;	k--;
	if (num % k == 0)
		printf("%d\n", num / k);
	else
		printf("%d\n", num / k + 1);
	return 0;
}