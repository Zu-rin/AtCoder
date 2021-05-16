#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, days, ppl, i = 0, j, l, r, n, g;
	cin >> num >> days >> ppl;
	vector<int> left(days), right(days), now(ppl), goal(ppl);
	for (; i < days; i++)
		scanf_s("%d%d", &left[i], &right[i]);
	for (i = 0; i < ppl; i++) {
		scanf_s("%d%d", &now[i], &goal[i]);
		goal[i] -= now[i];
	}
	for (i = 0; i < days; i++) {
		l = left[i];
		r = right[i];
		for (j = 0; j < ppl; j++) {
			g = goal[j];
			n = now[j];
			if (g == 0 || n < l || r < n)
				continue;
			if (g > 0) {
				if (n + g <= r) {
					goal[j] = 0;
					now[j] = i + 1;
				}
				else {
					goal[j] += n - r;
					now[j] = r;
				}
			}
			else {
				if (n + g >= l) {
					goal[j] = 0;
					now[j] = i + 1;
				}
				else {
					goal[j] += n - l;
					now[j] = l;
				}
			}
		}
	}
	for (i = 0; i < ppl; i++)
		printf("%d\n", now[i]);
	return 0;
}