#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

pair<ll, ll> DFS(int x, int y, vector<string> &map, vector<vector<int>> &ok) {
	pair<ll, ll> ans = make_pair(0, 0), p;
	ok[y][x] = false;
	if (y > 0 && ok[y - 1][x] && map[y - 1][x] != map[y][x]) {
		p = DFS(x, y - 1, map, ok);
		ans.first += p.first;
		ans.second += p.second;
	}
	if (x > 0 && ok[y][x - 1] && map[y][x - 1] != map[y][x]) {
		p = DFS(x - 1, y, map, ok);
		ans.first += p.first;
		ans.second += p.second;
	}
	if (y < map.size() - 1 && ok[y + 1][x] && map[y + 1][x] != map[y][x]) {
		p = DFS(x, y + 1, map, ok);
		ans.first += p.first;
		ans.second += p.second;
	}
	if (x < map[0].size() - 1 && ok[y][x + 1] && map[y][x + 1] != map[y][x]) {
		p = DFS(x + 1, y, map, ok);
		ans.first += p.first;
		ans.second += p.second;
	}
	if (map[y][x] == '.')
		ans.first++;
	else
		ans.second++;
	return ans;
}

int main(void) {
	int h, w, num, i, j;
	ll ans = 0;
	cin >> h >> w;
	vector<string> s(h);
	pair<ll, ll> p;
	for (i = 0; i < h; i++)
		cin >> s[i];
	vector<vector<int>> d(h, vector<int>(w, true));
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (d[i][j]) {
				p = DFS(j, i, s, d);
				ans += p.first * p.second;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}