#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(void) {
	int num, i = 0, a, b;
	long long k;
	cin >> num >> k;
	vector<int> d;
	map<int, long long> mp;
	for (; i < num; i++) {
		scanf_s("%d%d", &a, &b);
		if (mp.find(a) == mp.end())
			d.push_back(a);
		mp[a] += b;
	}
	sort(d.begin(), d.end());
	i = -1;
	while (k > 0)
		k -= mp[d[++i]];
	cout << d[i] << "\n";
	return 0;
}