#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int A, B;

int Judge(int n, vector<int> &d) {
	int i, b = B * n;
	for (i = 0; i < d.size(); i++) {
		if (d[i] <= b)
			break;
		n -= (d[i] - b) / A;
		if ((d[i] - b) % A > 0)
			n--;
		if (n < 0)
			return false;
	}
	return true;
}

int Search(int l, int r, vector<int> &d) {
	if (l == r)
		return l;
	int p = (l + r) >> 1;
	if (Judge(p, d))
		return Search(l, p, d);
	else
		return Search(p + 1, r, d);
}

int main(void) {
	int num, i, m;
	ll sum = 0;
	cin >> num >> A >> B;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end(), greater<int>());
	A -= B;
	m = d[0] / B;
	if (d[0] % B > 0)
		m++;
	cout << Search(0, m, d) << "\n";
	return 0;
}