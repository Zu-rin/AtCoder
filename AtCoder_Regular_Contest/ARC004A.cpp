#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
	int num, i = 0, j;
	double ans = 0.0;
	cin >> num;
	vector<int> x(num), y(num);
	for (; i < num; i++)
		scanf_s("%d%d", &x[i], &y[i]);
	for (i = 0; i < num - 1; i++) {
		for (j = i + 1; j < num; j++) {
			ans = max(ans, pow(abs(x[i] - x[j]), 2) + pow(abs(y[i] - y[j]), 2));
		}
	}
	printf("%.9lf\n", sqrt(ans));
	return 0;
}