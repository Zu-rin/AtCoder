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
	friend bool operator==(const Point_Coordinates &l, const Point_Coordinates &r) {
		return l.i == r.i and l.j == r.j;
	}
	friend Point_Coordinates operator+(const Point_Coordinates& l, const Point_Coordinates& r) {
		return { l.i + r.i, l.j + r.j };
	}
} point;

const point dn[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int DFS(vector<string> &s, vector<vector<char>> &ok, const point st, point n, int dep = 0) {
	if (st == n and 3 <= dep)
		return dep;
	int i, ans = -1;
	rep(i, 4) {
		point nx = n + dn[i];
		if (ok[nx.i][nx.j] and s[nx.i][nx.j] == '.') {
			ok[nx.i][nx.j] = 0;
			chmax(ans, DFS(s, ok, st, nx, dep + 1));
			ok[nx.i][nx.j] = 1;
		}
	}
	return ans;
}

int main(void) {
	int num, i, j, h, w, ans = -1;
	cin >> h >> w;
	string t;
	vector<string> s(h + 2, string(w + 2, '#'));
	for (i = 1; i <= h; i++) {
		cin >> t;
		s[i] = "#" + t + "#";
	}
	for (i = 1; i <= h; i++) {
		for(j = 1; j <= w; j++) {
			if (s[i][j] == '.') {
				vector<vector<char>> ok(h + 2, vector<char>(w + 2, 1));
				chmax(ans, DFS(s, ok, { i, j }, { i, j }));
			}
		}
	}
	cout << ans << "\n";
	return 0;
}