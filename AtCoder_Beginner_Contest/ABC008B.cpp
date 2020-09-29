#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	map<string, int> mp;
	string s, ans;
	int num, i, ma = 0;
	cin >> num;
	for (i = 0; i < num; i++) {
		cin >> s;
		mp[s]++;
		if (ma < mp[s]) {
			ma = mp[s];
			ans = s;
		}
	}
	cout << ans << "\n";
	return 0;
}