#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, n1, n2, a, b;
	cin >> num >> a >> b;
	for (int i = 0; i < num - 2; i++)
		scanf_s("%d", &a);
	cin >> n1;
	if (num == 1)
		a = abs(n1 - b);
	else {
		cin >> n2;
		a = max(abs(n2 - b), abs(n1 - n2));
	}
	printf("%d\n", a);
	return 0;
}