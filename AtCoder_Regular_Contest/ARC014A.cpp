#include <iostream>

using namespace std;

int main(void) {
	int num;
	cin >> num;
	if (num & 1)
		printf("Red\n");
	else
		printf("Blue\n");
	return 0;
}