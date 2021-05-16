#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, h, ans;
	string s;
	cin >> num >> h;
	getline(cin, s);
	vector<string> mp(h);
	for (i = 0; i < h; i++) {
		getline(cin, mp[i]);
	}
	getline(cin, s);
	ans = s.find('o');
	for (i = h - 1; i >= 0; i--) {
		if (ans > 0 && mp[i][ans - 1] == '-')
			ans -= 2;
		else if (ans < mp[i].size() - 1 && mp[i][ans + 1] == '-')
			ans += 2;
	}
	cout << (ans >> 1) + 1 << "\n";
	return 0;
}