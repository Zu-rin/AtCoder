#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int Even(string & s) {
	int i;
	vector<int> a(26, 0);
	rep(i, s.size()) {
		if (a[s[i] - 'a'])
			return 1;
		else
			a[s[i] - 'a'] = 1;
	}
	return 0;
}

int Search(string s, const string & t, int n = 0) {
	if (n == s.size())
		return 0;
	int i, ans = INF;
	if (s[n] != t[n]) {
		for (i = n + 1; i < s.size(); i++) {
			if (t[n] == s[i]) {
				string a = s;
				a[i] = a[n];
				a[n] = t[n];
				chmin(ans, Search(a, t, n + 1) + 1);
			}
		}
		return ans;
	}
	else
		return Search(s, t, n + 1);
}

int main(void) {
	int num, i, ok = 0, ev, ans;
	string s, t, a, b;
	cin >> s >> t;
	a = b = "";
	ev = Even(s);
	rep(i, s.size()) {
		if (s[i] != t[i]) {
			a += s[i];
			b += t[i];
		}
	}
	if (a.size() <= 6) {
		ans = Search(a, b);
		if (ans <= 3) {
			if ((ans & 1) || ev)
				ok = 1;
		}
	}
	if (ok)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}