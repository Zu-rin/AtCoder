#include <iostream>
#include <vector>

using namespace std;

int Search(int n, const vector<int> &par) {
	if (par[n] == n)
		return n;
	else
		return Search(par[n], par);
}

void uni(const int a, const int b, vector<int> &par, vector<int> &dep) {
	if (dep[a] < dep[b])
		par[a] = b;
	else if (dep[a] > dep[b])
		par[b] = a;
	else {
		par[b] = a;
		dep[a]++;
	}
}

int main(void) {
	int num, m, a, b, z, i = 0, ans = 0;
	scanf_s("%d%d", &num, &m);
	vector<int> par(num + 1), dep(num + 1, 0), exi(num + 1, true);
	for (; i <= num; i++)
		par[i] = i;
	for (i = 0; i < m; i++) {
		scanf_s("%d%d%d", &a, &b, &z);
		a = Search(a, par);
		b = Search(b, par);
		if (a != b)
			uni(a, b, par, dep);
	}
	for (i = 1; i <= num; i++) {
		a = Search(i, par);
		if (exi[a]) {
			ans++;
			exi[a] = false;
		}
	}
	printf("%d\n", ans);
	return 0;
}