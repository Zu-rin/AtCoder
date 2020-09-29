#include <iostream>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	if (k == 1)
		printf("0\n");
	else
		cout << n - k << "\n";
	return 0;
}