#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, i = 0, j = 0;
	double ans = 0.0, buf;
	cin >> num;
	vector<int> d(num), k(num, 0);
	for (; i < num; i++)
		scanf_s("%d", &d[i]);
	for (; j < num; j++) {
		for (i = 0; i < num; i++) {
			if (d[j] % d[i] == 0)
				k[j]++;
		}
	}
	for (i = 0; i < num; i++) {
		buf = k[i];
		ans += ((k[i] / 2) + (k[i] % 2)) / buf;
	}
	printf("%lf\n", ans);
	return 0;
}