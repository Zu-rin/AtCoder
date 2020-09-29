#include <iostream>
#include <vector>

using namespace std;
int Par(int n, vector<int> &d) {
	if (d[n] == n)
		return n;
	int ans = Par(d[n], d);
	d[n] = ans;
	return ans;
}

int main(void) {
	int num, m, k, i, j, a, b;
	cin >> num >> m;
	vector<int> d(m + 1), l(m + 1, 0), t(num);
	for (i = 1; i <= m; i++)
		d[i] = i;
	for (i = 0; i < num; i++) {
		scanf_s("%d%d", &k, &t[i]);
		t[i] = Par(t[i], d);
		while (k > 1) {
			scanf_s("%d", &a);
			a = Par(a, d);
			if (l[t[i]] < l[a]) {
				d[t[i]] = a;
				t[i] = a;
			}
			else {
				d[a] = t[i];
				if (l[t[i]] == l[a])
					l[t[i]]++;
			}
			k--;
		}
	}
	a = Par(t[0], d);
	for (i = 1; i < num; i++) {
		if (a != Par(t[i], d)) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}