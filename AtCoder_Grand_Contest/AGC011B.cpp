#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int Judge(int tag, vector<ll> &d) {
	ll i, x = 0;
	for (i = 0; i <= tag; i++)
		x += d[i];
	for (; i < d.size(); i++) {
		if ((x << 1) < d[i])
			return false;
		x += d[i];
	}
	return true;
}

int Search(vector<ll> &d, int l, int r) {
	if (l == r)
		return l;
	int tag = (l + r) >> 1;
	if (Judge(tag, d))
		return Search(d, l, tag);
	else
		return Search(d, tag + 1, r);
}

int main(void) {
	int num, i;
	cin >> num;
	vector<ll> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%lld", &d[i]);
	sort(d.begin(), d.end());
	i = Search(d, 0, num - 1);
	cout << num - i << "\n";
	return 0;
}