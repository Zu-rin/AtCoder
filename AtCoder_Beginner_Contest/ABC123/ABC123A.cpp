#include <iostream>

using namespace std;

int main(void) {
	int a[5], i = 0, k;
	for (; i < 5; i++)
		cin >> a[i];
	cin >> k;
	if (a[4] - a[0] > k)
		cout << ":(\n";
	else
		cout << "Yay!\n";
	return 0;
}