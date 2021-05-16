#include <iostream>

using namespace std;

int main(void) {
	int a;
	bool y = false;
	cin >> a;
	if (a % 4 == 0 && a % 100 != 0)
		y = true;
	else if (a % 400 == 0)
		y = true;
	if (y)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}