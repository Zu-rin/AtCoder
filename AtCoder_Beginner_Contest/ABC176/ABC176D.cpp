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
typedef struct Point_Coordinates {
	int i, j;
	friend Point_Coordinates operator+(const Point_Coordinates& l, const Point_Coordinates& r) {
		return { l.i + r.i, l.j + r.j };
	}
} point;

void DFS(point n, int k, vector<string>& s, vector<vector<int>>& d) {
	int i;
	point dn[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	d[n.i][n.j] = k;
	rep(i, 4) {
		point a = n + dn[i];
		if (s[a.i][a.j] == '.' && d[a.i][a.j] == 0)
			DFS(a, k, s, d);
	}
	return;
}

int Divide(vector<string>& s, vector<vector<int>>& d) {
	int i, j, k = 1;
	for (i = 1; i < s.size(); i++) {
		for (j = 1; j < s[i].size(); j++) {
			if (s[i][j] == '.' && d[i][j] == 0) {
				DFS({ i, j }, k, s, d);
				k++;
			}
		}
	}
	return k;
}

void Solve(int s, int dep, vector<set<int>>& d, vector<int> & ans) {
	queue<int> que;
	ans[s] = 0;
	que.push(s);
	while (!que.empty()) {
		s = que.front();
		que.pop();
		for (auto it = d[s].begin(); it != d[s].end(); it++) {
			if (ans[*it] == INF) {
				ans[*it] = ans[s] + 1;
				que.push(*it);
			}
		}
	}
}

int main(void) {
	int num, i, j, h, w, k;
	point s, e;
	cin >> h >> w;
	cin >> s.i >> s.j >> e.i >> e.j;
	vector<string> m(h + 2, string(w + 2, '#'));
	vector<vector<int>> d(h + 2, vector<int>(w + 2, 0));
	for (i = 1; i <= h; i++) {
		cin >> m[i];
		m[i] = "#" + m[i] + "#";
	}
	k = Divide(m, d);
	vector<set<int>> st(k);
	for (i = 1; i < d.size(); i++) {
		for (j = 1; j < d[i].size(); j++) {
			if (d[i][j]) {
				for (int a = max(1, i - 2); a < min((int)d.size(), i + 3); a++) {
					for(int b = j; b < min((int)d[a].size(), j + 3); b++) {
						if (d[a][b] > 0 && d[a][b] != d[i][j]) {
							st[d[i][j]].insert(d[a][b]);
							st[d[a][b]].insert(d[i][j]);
						}
					}
				}
			}
		}
	}
	vector<int> ans(k, INF);
	Solve(d[s.i][s.j], 0, st, ans);
	if (ans[d[e.i][e.j]] == INF)
		printf("-1\n");
	else
		cout << ans[d[e.i][e.j]] << "\n";
	return 0;
}