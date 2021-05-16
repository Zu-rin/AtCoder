#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, a = 0, ans;
	double b, c = 1000000000, buf;
	cin >> num;
	vector<int> d(num);
	for (i = 0; i < num; i++) {
		scanf_s("%d", &d[i]);
		a = max(a, d[i]);
	}
	b = (double)a / 2;
	for (i = 0; i < num; i++) {
		buf = (double)d[i] - b;
		if (buf < 0)
			buf *= (double)-1;
		if (a != d[i] && c > buf) {
			c = buf;
			ans = d[i];
		}
	}
	printf("%d %d\n", a, ans);
	return 0;
}