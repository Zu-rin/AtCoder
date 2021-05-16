#include <iostream>
#include <vector>
#include <algorithm>
#define T true
#define F false

using namespace std;

int num, mm, ans = 0;

void Search(vector<int> &l, const vector<vector<bool>> &con, const vector<int> &p, int a) {
	int i = 0;
	if (a == num) {
		for (; i < mm; i++) {
			if ((l[i] & 1) != p[i])
				break;
		}
		if (i == mm)
			ans++;
		return;
	}
	vector<int> ll(mm);
	for (; i < mm; i++) {
		if (con[a][i])
			ll[i] = l[i] + 1;
		else
			ll[i] = l[i];
	}
	Search(ll, con, p, a + 1);
	Search(l, con, p, a + 1);
	return;
}

int main(void) {
	int i = 0, j, a, k;
	cin >> num >> mm;
	vector<int> light(mm, 0), p(mm);
	vector<vector<bool>> con(num, vector<bool>(mm, F));
	for (; i < mm; i++) {
		cin >> k;
		for (j = 0; j < k; j++) {
			scanf_s("%d", &a);
			con[a - 1][i] = T;
		}
	}
	for (i = 0; i < mm; i++)
		scanf_s("%d", &p[i]);
	Search(light, con, p, 0);
	printf("%d\n", ans);
	return 0;
}