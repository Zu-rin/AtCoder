#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
	int num, i = 0, id = 0;
	cin >> num;
	vector<int> d(num), s(num);
	map<int, int> mp;
	for (; i < num; i++) {
		scanf_s("%d", &d[i]);
		s[i] = d[i];
	}
	sort(s.begin(), s.end());
	mp[s[0]] = 0;
	for (i = 1; i < num; i++) {
		if (s[i - 1] < s[i]) {
			id++;
			mp[s[i]] = id;
		}
	}
	for (i = 0; i < num; i++)
		printf("%d\n", mp[d[i]]);
	return 0;
}