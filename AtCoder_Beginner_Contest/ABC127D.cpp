#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

int main(void) {
	int i = 0, j = 0, num, mm, b;
	ll ans = 0;
	cin >> num >> mm;
	vector<int> d(num), c(mm);
	map<int, ll> mp;
	for (; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	for (i = 0; i < mm; i++) {
		scanf_s("%d%d", &b, &c[i]);
		mp[c[i]] += b;
	}
	sort(c.begin(), c.end(), greater<int>());
	c.erase(unique(c.begin(), c.end()), c.end());
	for (i = 0, b = 0; i < num; i++) {
		if (j < c.size()) {
			ans += max(c[j], d[i]);
			mp[c[j]]--;
			if (mp[c[j]] == 0)
				j++;
		}
		else
			ans += d[i];
	}
	cout << ans;
	return 0;
}