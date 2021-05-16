#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int w, h, num, x, y, a, i;
	cin >> w >> h >> num;
	int xmin = 0, xmax = w, ymin = 0, ymax = h;
	for (i = 0; i < num; i++) {
		scanf_s("%d%d%d", &x, &y, &a);
		switch (a) {
		case 1:
			xmin = max(xmin, x);
			break;
		case 2:
			xmax = min(xmax, x);
			break;
		case 3:
			ymin = max(ymin, y);
			break;
		case 4:
			ymax = min(ymax, y);
			break;
		}
	}
	if (xmax <= xmin || ymax <= ymin)
		printf("0\n");
	else
		cout << (xmax - xmin) * (ymax - ymin) << "\n";
	return 0;
}