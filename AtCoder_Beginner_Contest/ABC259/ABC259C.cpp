#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
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
typedef pair<char, int> pp;

vector<pp> change(string & s) {
	int i, a = 1;
	vector<pp> ans;
	s += "#";
	rep(i, s.size() - 1) {
		if (s[i] != s[i + 1]) {
			ans.push_back(pp(s[i], a));
			a = 1;
		}
		else {
			a++;
		}
	}
	return ans;
}

int main(void) {
	int num, i, ok = 0;
	string s, t;
	vector<pp> a, b;
	cin >> s >> t;
	a = change(s);
	b = change(t);
	if (a.size() == b.size())
		ok = 1;
	rep(i, min(a.size(), b.size())) {
		if (a[i].first != b[i].first or a[i].second > b[i].second or a[i].second != b[i].second and a[i].second == 1) {
			ok = 0;
			break;
		}
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}