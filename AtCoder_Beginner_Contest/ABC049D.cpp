#include <iostream>
#include <vector>
#include <map>

using namespace std;

int Root(int a, vector<int> &v) {
	while (a != v[a])
		a = v[a];
	return a;
}

int main(void) {
	int num, rn, tn, i, a, b, p, q;
	cin >> num >> rn >> tn;
	num++;
	vector<int> r(num), t(num), rlen(num, 0), tlen(num, 0);
	map<pair<int, int>, int> mp;
	for (i = 1; i < num; i++) {
		r[i] = i;
		t[i] = i;
	}
	for (i = 0; i < rn; i++) {
		scanf_s("%d%d", &a, &b);
		p = Root(a, r);
		q = Root(b, r);
		if (rlen[p] <= rlen[q]) {
			r[p] = q;
			if (rlen[p] == rlen[q])
				rlen[q]++;
		}
		else
			r[q] = p;
	}
	for (i = 0; i < tn; i++) {
		scanf_s("%d%d", &a, &b);
		p = Root(a, t);
		q = Root(b, t);
		if (tlen[p] <= tlen[q]) {
			t[p] = q;
			if (tlen[p] == tlen[q])
				tlen[q]++;
		}
		else
			t[q] = p;
	}
	for (i = 1; i < num; i++)
		mp[make_pair(Root(i, r), Root(i, t))]++;
	for (i = 1; i < num; i++)
		printf("%d ", mp[make_pair(Root(i, r), Root(i, t))]);
	printf("\n");
	return 0;
}