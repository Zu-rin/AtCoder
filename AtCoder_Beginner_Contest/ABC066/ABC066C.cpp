#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, i = 0;
	cin >> num;
	vector<int> d(num);
	for (; i < num; i++)
		scanf_s("%d", &d[i]);
	for (i = num - 1; i > 0; i -= 2)
		printf("%d ", d[i]);
	cout << d[0];
	for (i = 2 - (num % 2); i < num - 1; i += 2)
		printf(" %d", d[i]);
	return 0;
}