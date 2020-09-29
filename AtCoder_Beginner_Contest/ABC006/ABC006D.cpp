#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Search(vector<int> &d, int tag, int l, int r) {
	if (l == r)
		return l;
	int pos = (l + r) / 2;
	if (tag < d[pos])
		return Search(d, tag, l, pos);
	else
		return Search(d, tag, pos + 1, r);
}

int main(void) {
	int num, i, a, p, ans = 1;
	cin >> num >> a;
	vector<int> d(num, num + 1);
	d[0] = a;
	for (i = 1; i < num; i++) {
		scanf("%d", &a);
		p = Search(d, a, 0, ans);
		ans = max(ans, p + 1);
		d[p] = min(d[p], a);
	}
	cout << num - ans << "\n";
	return 0;
}