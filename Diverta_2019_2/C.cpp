#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, x, y;
	cin >> num;
	vector<int> d(num), X(num - 1), Y(num - 1);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	x = d[num - 1];
	y = d[0];
	i = 1;
	while (i < num - 1 && d[i] < 0) {
		X[i] = x;
		Y[i] = d[i];
		x -= d[i++];
	}
	while (i < num - 1) {
		X[i] = y;
		Y[i] = d[i];
		y -= d[i++];
	}
	printf("%d\n", x - y);
	for (i = 1; i < num - 1; i++)
		printf("%d %d\n", X[i], Y[i]);
	printf("%d %d\n", x, y);
	return 0;
}