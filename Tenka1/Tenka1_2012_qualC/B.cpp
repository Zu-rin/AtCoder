#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <set>
#include <map>
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

void Div(const string &s, vector<string> & d) {
	int i, a = 0;
	string k = "SHDC";
	for(i = 1; i < s.size(); i++) {
		if (0 <= (int)k.find(s[i])) {
			d.push_back(s.substr(a, i - a));
			a = i;
		}
	}
	d.push_back(s.substr(a, i - a));
	return;
}

int Judge(string& s) {
	set<string> k = { "10", "J", "Q", "K", "A" };
	return k.count(s.substr(1, s.size() - 1));
}

int main(void) {
	int num, i;
	char c;
	vector<string> d;
	map<char, set<string>> mp;
	string s, ans = "";
	cin >> s;
	Div(s, d);
	rep(i, d.size()) {
		if (Judge(d[i])) {
			set<string>& st = mp[d[i][0]];
			st.insert(d[i]);
			if (st.size() == 5) {
				c = d[i][0];
				break;
			}
		}
	}
	set<string>& st = mp[c];
	rep(i, d.size()) {
		if (st.count(d[i])) {
			st.erase(d[i]);
			if(st.size() == 0)
				break;
		}
		else
			ans += d[i];
	}
	if (ans.size())
		cout << ans << "\n";
	else
		printf("0\n");
	return 0;
}