#include <iostream>
#include <vector>

using namespace std;

int buf = 0;

int Parent(int n, vector<int> &p, vector<int> &d) {
	if (p[n] == n) {
		buf = 0;
		return n;
	}
	p[n] = Parent(p[n], p, d);
	d[n] += buf;
	buf = d[n];
	return p[n];
}

int main(void) {
	int num, m, i, ok = true, a, l, r, lp, rp;
	cin >> num >> m;
	vector<int> p(num + 1), d(num + 1, 0);
	for (i = 1; i <= num; i++)
		p[i] = i;
	for (i = 0; i < m; i++) {
		scanf_s("%d%d%d", &l, &r, &a);
		lp = Parent(l, p, d);
		rp = Parent(r, p, d);
		if (lp == rp) {
			if (d[r] - d[l] != a) {
				ok = false;
				break;
			}
			continue;
		}
		a = d[l] + a - d[r];
		if (a >= 0) {
			p[rp] = p[lp];
			d[rp] = a;
		}
		else {
			p[lp] = p[rp];
			d[lp] = -a;
		}
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}