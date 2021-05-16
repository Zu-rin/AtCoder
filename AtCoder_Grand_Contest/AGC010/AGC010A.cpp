#include <iostream>

using namespace std;

int main(void) {
	int num, odd = 0, a, i;
	cin >> num;
	for (i = 0; i < num; i++) {
		scanf_s("%d", &a);
		if (a & 1)
			odd++;
	}
	if (odd & 1)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}