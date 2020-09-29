#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, mi = 1e9, ma = 0 , i = 0, a, ans = 0;
	cin >> num >> a;
	vector<int> d(num);
	for (; i < num; i++) {
		scanf_s("%d", &a);
		mi = min(mi, a);
		d[i] = a - mi;
		ma = max(ma, d[i]);
	}
	for (i = 0; i < num; i++) {
		if (d[i] == ma)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}