#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, aa, bb, as = 0, bs = 0, an, bn, ans;
	cin >> num;
	vector<int> a(100001, 0), b(100001, 0);
	for (; i < (num >> 1); i++) {
		scanf_s("%d%d", &aa, &bb);
		a[aa]++;
		b[bb]++;
	}
	for (aa = 0, bb = 0, i = 0; i < 100000; i++) {
		if (aa < a[i]) {
			as = aa;
			aa = a[i];
			an = i;
		}
		else if (as < a[i])
			as = a[i];
		if (bb < b[i]) {
			bs = bb;
			bb = b[i];
			bn = i;
		}
		else if (bs < b[i])
			bs = b[i];
	}
	if (an == bn)
		ans = max(aa + bs, bb + as);
	else
		ans = aa + bb;
	printf("%d\n", num - ans);
	return 0;
}