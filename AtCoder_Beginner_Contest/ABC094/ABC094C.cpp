#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, ans1, ans2;
	double v;
	cin >> num;
	vector<int> d(num), a(num);
	for (; i < num; i++) {
		scanf_s("%d", &d[i]);
		a[i] = d[i];
	}
	sort(d.begin(), d.end());
	ans1 = d[num / 2 - 1];
	ans2 = d[num / 2];
	v = (double)(ans1 + ans2) / 2;
	for (i = 0; i < num; i++) {
		if (a[i] > v)
			printf("%d\n", ans1);
		else
			printf("%d\n", ans2);
	}
	return 0;
}