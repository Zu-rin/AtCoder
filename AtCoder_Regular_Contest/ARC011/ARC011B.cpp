#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j;
	cin >> num;
	vector<int> d(26, -1);
	string s, ans = "", a;
	d['b' - 'a'] = d['c' - 'a'] = 1;
	d['d' - 'a'] = d['w' - 'a'] = 2;
	d['t' - 'a'] = d['j' - 'a'] = 3;
	d['f' - 'a'] = d['q' - 'a'] = 4;
	d['l' - 'a'] = d['v' - 'a'] = 5;
	d['s' - 'a'] = d['x' - 'a'] = 6;
	d['p' - 'a'] = d['m' - 'a'] = 7;
	d['h' - 'a'] = d['k' - 'a'] = 8;
	d['n' - 'a'] = d['g' - 'a'] = 9;
	d['z' - 'a'] = d['r' - 'a'] = 0;
	for (i = 0; i < num; i++) {
		cin >> s;
		a = "";
		for (j = 0; j < s.size(); j++) {
			if (s[j] >= 'A' && s[j] <= 'Z')
				s[j] += 32;
			if (s[j] >= 'a' && s[j] <= 'z' && d[s[j] - 'a'] >= 0) {
				a += '0' + d[s[j] - 'a'];
			}
		}
		if (a.size() > 0) {
			if (ans.size() > 0)
				ans += " ";
			ans += a;
		}
	}
	cout << ans << "\n";
	return 0;
}