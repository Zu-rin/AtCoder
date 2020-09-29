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
typedef struct Point_Coordinates {
	int i, j;

	Point_Coordinates(){}

	Point_Coordinates(int a, int b) {
		i = a;
		j = b;
	}

	friend bool operator<(const Point_Coordinates& left, const Point_Coordinates& right) {
		return left.i < right.i;
	}
} point;
typedef pair<int, point> pp;

int Dijk(point s, point g, vector<string>& mp) {
	int i, j;
	point dn[4] = { {0,1}, {1,0}, {0,-1}, {-1, 0} };
	priority_queue<pp, vector<pp>, greater<pp>> que;
	vector<vector<int>> ans(mp.size(), vector<int>(mp[0].size(), INF));
	que.push(pp(0, s));
	while (!que.empty()) {
		pp a = que.top();
		point n = a.second;
		que.pop();
		if (ans[n.i][n.j] != INF)
			continue;
		ans[n.i][n.j] = a.first;
		rep(i, 4) {
			point nx(n.i + dn[i].i, n.j + dn[i].j);
			if (ans[nx.i][nx.j] == INF) {
				if (mp[nx.i][nx.j] == '#')
					que.push(pp(a.first + 1, nx));
				else if (mp[nx.i][nx.j] != '!')
					que.push(pp(a.first, nx));
			}
		}
	}
	return ans[g.i][g.j];
}

int main(void) {
	int num, i, h, w, ans, p;
	point s, g;
	cin >> h >> w;
	vector<string> mp(h + 2, string(w + 2, '!'));
	for (i = 1; i <= h; i++) {
		cin >> mp[i];
		mp[i] = "!" + mp[i] + "!";
		p = mp[i].find("s");
		if (p > 0)
			s = point(i, p);
		p = mp[i].find("g");
		if (p > 0)
			g = point(i, p);
	}
	ans = Dijk(s, g, mp);
	if (ans > 2)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}