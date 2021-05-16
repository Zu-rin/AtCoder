#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, sum = 0, buf, len;
	cin >> num;
	vector<int> d(num + 2, 0);
	for (i = 1; i < num + 1; i++)
		scanf_s("%d", &d[i]);
	for (i = 0; i < num + 1; i++)
		sum += abs(d[i] - d[i + 1]);
	buf = abs(d[0] - d[1]);
	for (i = 1; i < num + 1; i++) {
		len = abs(d[i] - d[i + 1]);
		printf("%d\n", sum - buf - len + abs(d[i - 1] - d[i + 1]));
		buf = len;
	}
	return 0;
}