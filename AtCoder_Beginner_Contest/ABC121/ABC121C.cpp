#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	int num, mm, i = 0;
	long long a, ans = 0, cost = -1;
	cin >> num >> mm;
	vector<int> d(num);
	map<int, int> mp;
	for (; i < num; i++) {
		scanf_s("%d%d", &d[i], &a);
		mp[d[i]] += a;
	}
	sort(d.begin(), d.end());
	i = 0;
	while (mm > 0) {
		while (cost == d[i])
			i++;
		cost = d[i];
		a = min(mp[cost], mm);
		ans += cost * a;
		mm -= a;
	}
	cout << ans << "\n";
	return 0;
}