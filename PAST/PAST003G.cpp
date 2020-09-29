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
	int x, y;
} point;

queue<point> que;
vector<point> dd = { {1,1}, {0,1},{-1,1},{1,0},{-1,0},{0,-1} };
void Search(point s, vector<vector<int>>& mp, vector<vector<int>> &ans) {
	int i;
	point n = s;
	while (true) {
		rep(i, dd.size()) {
			point nx = { n.x + dd[i].x, n.y + dd[i].y };
			if (mp[nx.y][nx.x] && ans[nx.y][nx.x] == INF) {
				que.push(nx);
				ans[nx.y][nx.x] = ans[n.y][n.x] + 1;
			}
		}
		if (!que.empty()) {
			n = que.front();
			que.pop();
		}
		else
			break;
	}
	return;
}

int main(void) {
	int num, i, j, x, y;
	point s = { 250,250 }, g;
	vector<vector<int>> mp(501, vector<int>(501, true)), ans(501, vector<int>(501, INF));
	cin >> num >> g.x >> g.y;
	rep(i, 501)
		mp[0][i] = mp[500][i] = mp[i][0] = mp[i][500] = false;
	g.x += 250;
	g.y += 250;
	ans[s.y][s.x] = 0;
	rep(i, num) {
		cin >> x >> y;
		mp[y + 250][x + 250] = false;
	}
	Search(s, mp, ans);
	if (ans[g.y][g.x] == INF)
		printf("-1\n");
	else
		cout << ans[g.y][g.x] << "\n";
	return 0;
}