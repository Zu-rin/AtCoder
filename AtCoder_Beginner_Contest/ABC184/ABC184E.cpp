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
typedef struct Point_Coordinates {
	int i, j;
	Point_Coordinates friend operator+(Point_Coordinates& l, Point_Coordinates& r) {
		return { l.i + r.i, l.j + r.j };
	}
} point;

void Search(point b, vector<string>& s, vector<vector<point>> &p, vector<vector<int>> &ans) {
	int i;
	vector<point> dn = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	queue<point> que;
	que.push(b);
	ans[b.i][b.j] = 0;
	while (!que.empty()) {
		point n = que.front();
		que.pop();
		rep(i, 4) {
			point nx = n + dn[i];
			if (s[nx.i][nx.j] != '#' && ans[nx.i][nx.j] == INF) {
				ans[nx.i][nx.j] = ans[n.i][n.j] + 1;
				que.push(nx);
			}
		}
		if ('a' <= s[n.i][n.j] && s[n.i][n.j] <= 'z') {
			for (point nx : p[s[n.i][n.j] - 'a']) {
				if (ans[nx.i][nx.j] == INF) {
					ans[nx.i][nx.j] = ans[n.i][n.j] + 1;
					que.push(nx);
				}
			}
			p[s[n.i][n.j] - 'a'].clear();
		}
	}
	return;
}

int main(void) {
	int num, i, j, h, w;
	point b, e;
	cin >> h >> w;
	vector<string> s(h + 2, string(w + 2, '#'));
	vector<vector<int>> ans(h + 2, vector<int>(w + 2, INF));
	vector<vector<point>> p(26);
	rep(i, h) {
		cin >> s[i + 1];
		s[i + 1] = "#" + s[i + 1] + "#";
	}
	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			if (s[i][j] == 'S')
				b = { i, j };
			else if (s[i][j] == 'G')
				e = { i, j };
			else if ('a' <= s[i][j] && s[i][j] <= 'z')
				p[s[i][j] - 'a'].push_back({ i, j });
		}
	}
	Search(b, s, p, ans);
	if (ans[e.i][e.j] == INF)
		printf("-1\n");
	else
		cout << ans[e.i][e.j] << "\n";
	return 0;
}