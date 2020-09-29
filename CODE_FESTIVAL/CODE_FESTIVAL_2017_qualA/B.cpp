#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int h, w, H, W, i, x, y, k, ok = false;
	cin >> h >> w >> k;
	H = max(h, w);
	W = min(h, w);
	for (i = 0; !ok && i <= W; i++) {
		x = k - i * H;
		y = W - (i << 1);
		if (y == 0) {
			if (x == 0)
				ok = true;
		}
		else if (x % y == 0) {
			x /= y;
			if (x >= 0 && x <= H)
				ok = true;
		}
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}