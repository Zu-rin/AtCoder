#include <iostream>

using namespace std;

int main(void) {
	int num, i = 0, buf, mi = 0, ma, d[13] = { 0 };
	cin >> num;
	for (; i < num; i++) {
		scanf_s("%d", &buf);
		d[buf / 400]++;
	}
	ma = d[8] + d[9] + d[10] + d[11] + d[12];
	for (i = 0; i < 8; i++) {
		if (d[i] > 0)
			mi++;
	};
	ma += mi;
	if (mi == 0)
		mi = 1;
	printf("%d %d\n", mi, ma);
	return 0;
}