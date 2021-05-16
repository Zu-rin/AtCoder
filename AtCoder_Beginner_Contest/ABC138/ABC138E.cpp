#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;

queue<int> que;

int Search(const int c, int n, vector<vector<int>> &d, int l, int r) {
	if (l == r)
		return d[c][l];
	int p = (l + r) >> 1;
	if (d[c][p] <= n)
		return Search(c, n, d, p + 1, r);
	else
		return Search(c, n, d, l, p);
}

int main(void) {
	int num, q, i, a = 0, b;
	ll ans = 0;
	string s, t;
	cin >> s >> t;
	vector<vector<int>> d(26, vector<int>(s.size(), 0));
	vector<int> len(26, -1);
	for (i = 0; i < s.size(); i++) {
		len[s[i] - 'a']++;
		d[s[i] - 'a'][len[s[i] - 'a']] = i + 1;
	}
	for (i = 0; i < t.size(); i++) {
		if (len[t[i] - 'a'] < 0) {
			printf("-1\n");
			return 0;
		}
		b = Search(t[i] - 'a', a, d, 0, len[t[i] - 'a']);
		if (b <= a) {
			ans += s.size() - a + d[t[i] - 'a'][0];
			a = d[t[i] - 'a'][0];
		}
		else {
			ans += b - a;
			a = b;
		}
	}
	cout << ans << "\n";
	return 0;
}
