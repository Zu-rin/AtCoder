#include <iostream>

using namespace std;

int main(void) {
	int num, i = 0, a, b;
	long long asum = 0, bsum = 0, anx, bnx;
	cin >> num;
	for (; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		anx = a;
		bnx = b;
		if (asum > anx) {
			anx = (asum / a)*a;
			if (asum > anx)
				anx += a;
			bnx = (anx / a)*b;
		}
		if (bsum > bnx) {
			bnx = (bsum / b)*b;
			if (bsum > bnx)
				bnx += b;
			anx = (bnx / b)*a;
		}
		asum = anx;
		bsum = bnx;
	}
	cout << asum + bsum << "\n";
	return 0;
}