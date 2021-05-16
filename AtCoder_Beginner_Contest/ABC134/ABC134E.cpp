#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000

using namespace std;

int Search(int n, vector<int> &p, int l, int r) {
	if (l == r) {
		if (p[l] == MAX)
			r++;
		p[l] = min(p[l], n);
		return r;
	}
	int pos = (l + r) >> 1;
	if (p[pos] <= n)
		return Search(n, p, pos + 1, r);
	else
		return Search(n, p, l, pos);
}

int main(void) {
	int num, i, size = 0;
	cin >> num;
	vector<int> d(num), t(num, true), p(num, MAX);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	for (i = num - 1; i >= 0; i--) {
		size = max(size, Search(d[i], p, 0, size));
	}
	printf("%d\n", size);
	return 0;
}