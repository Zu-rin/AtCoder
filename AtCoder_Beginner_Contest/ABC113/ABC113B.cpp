#include <iostream>

using namespace std;

int main(void) {
	int num, ans = 1;
	double t, a, dis, buf;
	cin >> num >> t >> a >> buf;
	dis = a - (t - buf * 0.006);
	if (dis < 0)
		dis *= -1.0;
	for (int i = 2; i <= num; i++) {
		cin >> buf;
		buf = a - (t - buf * 0.006);
		if (buf < 0)
			buf *= -1.0;
		if (dis > buf) {
			dis = buf;
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}