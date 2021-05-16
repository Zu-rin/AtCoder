#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, ans = 0;
	cin >> num;
	vector<pair<int, int>> d(num);
	for (i = 0; i < num; i++) {
		scanf_s("%d", &d[i].first);
		d[i].second = i;
	}
	sort(d.begin(), d.end());
	for (i = 0; i < num; i += 2) {
		if (d[i].second & 1)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}