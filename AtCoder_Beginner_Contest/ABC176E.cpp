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
	friend bool operator<(const Point_Coordinates& l, const Point_Coordinates& r) {
		return l.i < r.i;
	}
} point;


int main(void) {
	int num, i, h, w, ans = 0;
	ll x = 0, y = 0;
	cin >> h >> w >> num;
	point p;
	vector<int> a(h + 1, 0), b(w + 1, 0);
	vector<point> d(num);
	rep(i, num) {
		cin >> p.i >> p.j;
		d[i] = p;
		a[p.i]++;
		b[p.j]++;
	}
	p.i = p.j = 0;
	rep(i, a.size()) {
		if (p.i < a[i])
			p.i = a[i];
	}
	rep(i, a.size()) {
		if (a[i] == p.i)
			x++;
	}
	rep(i, b.size()) {
		if (p.j < b[i])
			p.j = b[i];
	}
	rep(i, b.size()) {
		if (b[i] == p.j)
			y++;
	}
	x *= y;
	rep(i, num) {
		if (a[d[i].i] == p.i && b[d[i].j] == p.j)
			x--;
	}
	ans = p.i + p.j;
	if (x == 0)
		ans--;
	cout << ans << "\n";
	return 0;
}