#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1<<29

using namespace std;

int Cost(vector<int> const &d, int k) {
	int i = 0, ans = 0;
	for (; i < d.size(); i++)
		ans += (d[i] - k) * (d[i] - k);
	return ans;
}

int main(void) {
	int num, i = 0, mi = 100, ma = -100, ans = INF;
	cin >> num;
	vector<int> d(num);
	for (; i < num; i++) {
		scanf_s("%d", &d[i]);
		mi = min(mi, d[i]);
		ma = max(ma, d[i]);
	}
	for (i = mi; i <= ma; i++)
		ans = min(ans, Cost(d, i));
	cout << ans << "\n";
	return 0;
}