#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <set>
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

int Connect(const string & a, const string & b) {
	int i, d = 0;
	rep(i, a.size()) {
		if (a[i] != b[i])
			d++;
	}
	return d == 1;
}
void Search(int s, vector<list<int>>& ed, vector<int>& ans) {
	queue<pp> que;
	que.push(pp(s, 0));
	while (!que.empty()) {
		int n = que.front().first, c = que.front().second;
		que.pop();
		if (ans[n] == INF) {
			ans[n] = c;
			for (auto it = ed[n].begin(); it != ed[n].end(); it++) {
				if (ans[*it] == INF)
					que.push(pp(*it, c + 1));
			}
		}
	}
	return;
}

void Print(int g, vector<string>& s, vector<list<int>>& d, vector<int>& ans) {
	if (ans[g] == INF) {
		printf("-1\n");
		return;
	}
	int i, n = g;
	vector<string> a;
	while (ans[n] > 0) {
		a.push_back(s[n]);
		for (auto it = d[n].begin(); it != d[n].end(); it++) {
			if (ans[*it] < ans[n]) {
				n = *it;
				break;
			}
		}
	}
	a.push_back(s[n]);
	reverse(a.begin(), a.end());

	cout << max(0, (int)a.size() - 2) << "\n";
	if (a.size() == 1)
		cout << a[0] << "\n";
	rep(i, a.size())
		cout << a[i] << "\n";
	return;
}

int main(void) {
	int num, i, j, s, e;
	string S, E, a;
	vector<string> d;
	set<string> st;
	cin >> S >> E >> num;
	st.insert(S);
	st.insert(E);
	rep(i, num) {
		cin >> a;
		st.insert(a);
	}
	for (auto it = st.begin(); it != st.end(); it++) {
		if (S == *it)
			s = d.size();
		if (E == *it)
			e = d.size();
		d.push_back(*it);
	}
	num = d.size();
	vector<int> ans(num, INF);
	vector<list<int>> ed(num);
	rep(i, d.size()) {
		ed[i].push_back(i);
		for (j = i + 1; j < d.size(); j++) {
			if (Connect(d[i], d[j])) {
				ed[i].push_back(j);
				ed[j].push_back(i);
			}
		}
	}
	Search(s, ed, ans);
	Print(e, d, ed, ans);
	return 0;
}