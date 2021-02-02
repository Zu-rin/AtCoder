#include <iostream>
#include <vector>
#include <string>
#include <list>
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
typedef pair<int, int> pp;

int Search(int l, string &s) {
	int i;
	map<string, int> st;
	rep(i, s.size() - l + 1) {
		string t = s.substr(i, l);
		if (st.count(t)) {
			if(st[t] + l <= i)
				return 1;
		}
		else
			st[t] = i;
	}
	return 0;
}

int main(void) {
	int l = 0, r;
	string s;
	cin >> r >> s;
	while (l + 1 < r) {
		int p = (l + r) / 2;
		Search(p, s) ? l = p : r = p;
	}
	cout << l << "\n";
	return 0;
}