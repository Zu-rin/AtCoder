#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

void Ini(vector<double> &k) {
	for (int i = 2; i < k.size(); i++)
		k[i] = k[i - 1] + log10((double)i);
	return;
}

double Combi(int n, int a, const vector<double> &l) {
	a = min(a, n - a);
	return l[n] - l[a] - l[n -a];
}

int main(void) {
	int n, m, i, a = 0, b;
	cin >> n >> m;
	double ans = log10(1.0 / m) * n, x = 1.0 / (double)m;
	vector<double> l(n + 1, 0);
	Ini(l);
	for (i = 0; i < m; i++) {
		scanf_s("%d", &a);
		ans += (double)Combi(n, a, l);
		n -= a;
	}
	a = (int)ans;
	if (ans - a < 0)
		a--;
	cout << -a << "\n";
	return 0;
}