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

queue<vector<char>> que;
void Search(vector<char> &s, vector<vector<int>> &d, map<vector<char>, int> &ans) {
	que.push(s);
	while (!que.empty()) {
		vector<char> p = que.front();
		que.pop();
		int n = find(p.begin(), p.end(), (char)8) - p.begin();
		int c = ans[p];
		for (int nx : d[n]) {
			swap(p[n], p[nx]);
			if (!ans.count(p)) {
				que.push(p);
				ans[p] = c + 1;
			}
			swap(p[n], p[nx]);
		}
	}
	return;
}

int main(void) {
	int m, i, a, b;
	vector<vector<int>> d(9);
	vector<char> p(9, 8);
	map<vector<char>, int> ans;
	cin >> m;
	rep(i, m) {
		cin >> a >> b;
		d[--a].push_back(--b);
		d[b].push_back(a);
	}
	rep(i, 8) {
		cin >> a;
		p[--a] = i;
	}
	Search(p, d, ans);
	vector<char> tag(9);
	rep(i, 9)
		tag[i] = i;
	if (ans.count(tag))
		cout << ans[tag] << "\n";
	else
		printf("-1\n");
	return 0;
}