#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;
typedef struct {
	double x, y;
} point;

point Vertic(double r, point &a, point &b) {
	double h, k;
	h = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) / 2.0;
	if (r < h)
		return { 0, 0 };
	k = sqrt(r * r - h * h);
	point ans = { a.y - b.y, b.x - a.x };
	ans = { ans.x * k / (h * 2.0), ans.y * k / (h * 2.0) };
	return ans;
}

int Out(point &a, double r, vector<point>& d) {
	r *= r;
	for (int i = 0; i < d.size(); i++) {
		if (r < (a.x - d[i].x) * (a.x - d[i].x) + (a.y - d[i].y) * (a.y - d[i].y))
			return false;
	}
	return true;
}

int Judge(double r, vector<point>& d) {
	int i, j;
	point a, b, ab, v, p1, p2;
	for (i = 0; i < d.size() - 1; i++) {
		a = d[i];
		for (j = i + 1; j < d.size(); j++) {
			b = d[j];
			ab = { (b.x + a.x) / 2.0, (b.y + a.y) / 2.0 };
			v = Vertic(r, a, b);
			p1 = { ab.x + v.x, ab.y + v.y };
			p2 = { -p1.x, -p1.y };
			if (Out(p1, r, d) && Out(p2, r, d))
				return false;
		}
	}
	return true;
}

int main(void) {
	int num, i;
	double ans, out = 0.0, safe = 2000.0, r;
	cin >> num;
	vector<point> d(num);
	rep(i, num)
		cin >> d[i].x >> d[i].y;
	rep(i, 100) {
		r = (out + safe) / 2.0;
		if (Judge(r, d))
			safe = r;
		else
			out = r;
	}
	ans = safe;
	printf("%.10lf\n", ans);
	return 0;
}