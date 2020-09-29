#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int Binary_search(int n, vector<int>&d, int l, int r) {
	if (l == r) {
		if (n > d[l])
			return l + 1;
		else
			return l;
	}
	int p = (r + l) >> 1;
	if (n <= d[p])
		return Binary_search(n, d, l, p);
	else
		return Binary_search(n, d, p + 1, r);
}

int main(void) {
	int num, i, j;
	ll ans = 0;
	cin >> num;
	vector<int> d(num);
	for (i = 0; i < num; i++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			ans += Binary_search(d[i] + d[j], d, 0, num - 1) - j - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}