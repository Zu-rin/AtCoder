#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

typedef struct Point_Coordinates {
	int x, y;
} point;

queue<point> que;
void BFS(point n, vector<string> & mp, vector<vector<int>> & ans) {
	int x = n.x, y = n.y;
	if (x > 0 && mp[y][x - 1] == '.') {
		que.push({ x - 1, y });
		mp[y][x - 1] = '#';
		ans[y][x - 1] = ans[y][x] + 1;
	}
	if (y > 0 && mp[y - 1][x] == '.') {
		que.push({ x, y - 1 });
		mp[y - 1][x] = '#';
		ans[y - 1][x] = ans[y][x] + 1;
	}
	if (x < mp[0].size() - 1 && mp[y][x + 1] == '.') {
		que.push({ x + 1, y });
		mp[y][x + 1] = '#';
		ans[y][x + 1] = ans[y][x] + 1;
	}
	if (y < mp.size() - 1 && mp[y + 1][x] == '.') {
		que.push({ x, y + 1 });
		mp[y + 1][x] = '#';
		ans[y + 1][x] = ans[y][x] + 1;
	}
	if (que.empty())
		return;
	n = que.front();
	que.pop();
	BFS(n, mp, ans);
	return;
}

int main(void) {
	int num, i, j, h, w, a, b, ans = 0;
	cin >> h >> w;
	vector<string> s(h), buf(h);
	rep(i, h)
		cin >> s[i];
	rep(j, h) {
		rep(i, w) {
			if (s[j][i] == '.') {
				buf = s;
				vector<vector<int>> d(h, vector<int>(w, 0));
				buf[j][i] = '#';
				BFS({ i, j }, buf, d);
				rep(a, h) {
					rep(b, w) {
						chmax(ans, d[a][b]);
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}