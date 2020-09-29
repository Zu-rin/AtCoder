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
	friend bool operator<(const Point_Coordinates& l, const Point_Coordinates& r) {
		return l.i < r.i;
	}
} point;
typedef pair<ll, point> pp;

point dn[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
point st, go;
ll Search(vector<string>& s, int x) {
	int i;
	point n = st;
	priority_queue<pp, vector<pp>, greater<pp>> que;
	vector<vector<ll>> ans(s.size(), vector<ll>(s[0].size(), INF));
	ans[st.i][st.j] = 0;
	while (true) {
		rep(i, 4) {
			point nx = { n.i + dn[i].i, n.j + dn[i].j };
			if (ans[nx.i][nx.j] != INF)
				continue;
			else if (s[nx.i][nx.j] == '.')
				que.push(pp(ans[n.i][n.j] + 1, nx));
			else if (s[nx.i][nx.j] == '#')
				que.push(pp(ans[n.i][n.j] + x, nx));
		}
		if (que.empty())
			break;
		auto tag = que.top();
		que.pop();
		n = tag.second;
		ans[n.i][n.j] = tag.first;
	}
	return ans[go.i][go.j];
}

int BinarySearch(int l, int r, int t, vector<string> &s) {
	if (l == r)
		return l;
	int p = ((l + r) >> 1) + 1;
	if (Search(s, p) <= t)
		return BinarySearch(p, r, t, s);
	else
		return BinarySearch(l, p - 1, t, s);
}

int main(void) {
	int num, i, j, h, w, t, ans;
	cin >> h >> w >> t;
	string a;
	vector<string> s(h + 2, string(w + 2, '!'));
	for(i = 1; i <= h; i++) {
		cin >> a;
		s[i] = "!" + a + "!";
		if ((j = a.find("S")) >= 0)
			st = { i,j + 1 };
		if ((j = a.find("G")) >= 0)
			go = { i,j + 1 };
	}
	s[go.i][go.j] = '.';
	ans = BinarySearch(1, t, t, s);
	cout << ans << "\n";
	return 0;
}