#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, i = 0, xx, yy, ax, ay, ah = 0, hh;
	cin >> num;
	vector<int> x(num), y(num), h(num);
	for (; i < num; i++)
		scanf_s("%d%d%d", &x[i], &y[i], &h[i]);
	for (i = 0; i < num; i++) {
		if (h[i] != 0) {
			xx = x[0];
			yy = y[0];
			hh = h[0];
			x[0] = x[i];
			y[0] = y[i];
			h[0] = h[i];
			x[i] = xx;
			y[i] = yy;
			h[i] = hh;
			break;
		}
	}
	for (yy = 0; yy <= 100; yy++) {
		for (xx = 0; xx <= 100; xx++) {
			hh = h[0] + abs(x[0] - xx) + abs(y[0] - yy);
			for (i = 1; i < num; i++) {
				if (h[i] == 0) {
					if (hh > abs(x[i] - xx) + abs(y[i] - yy))
						break;
				}
				else if (hh != h[i] + abs(x[i] - xx) + abs(y[i] - yy))
					break;
			}
			if (i == num && ah <= hh) {
				ax = xx;
				ay = yy;
				ah = hh;
			}
		}
	}
	printf("%d %d %d\n", ax, ay, ah);
	return 0;
}