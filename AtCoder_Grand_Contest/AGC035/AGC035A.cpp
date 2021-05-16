#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define F false

using namespace std;

int main(void) {
	int num, i, ok = true;
	cin >> num;
	vector<int> d(num), a;
	map<int, int> mp;
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	a.push_back(d[0]);
	mp[d[0]]++;
	for (i = 1; i < num; i++) {
		if (d[i - 1] != d[i])
			a.push_back(d[i]);
		mp[d[i]]++;
	}
	switch (a.size()) {
	case 1:
		if ((a[0] ^ a[0]) != a[0])
			ok = F;
		break;
	case 2:
		if (a[0] == 0) {
			if (mp[a[0]] * 2 != mp[a[1]])
				ok = F;
		}
		else if (a[1] == 0) {
			if (mp[a[1]] * 2 != mp[a[0]])
				ok = F;
		}
		else
			ok = F;
		break;
	case 3:
		if ((a[0] ^ a[1]) != a[2])
			ok = F;
		for (i = 0; i < 2; i++) {
			if (mp[a[i]] != mp[a[i + 1]])
				ok = F;
		}
		break;
	default:
		ok = F;
		break;
	}
	if (ok)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}