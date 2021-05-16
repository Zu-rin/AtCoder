#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

typedef struct {
	double x, y;
} point;

double area(point& a, point& b, point& z) {
	return abs((b.x - a.x) * (z.y - a.y) - (b.y - a.y) * (z.x - a.x));
}

double leng(point& a, point& b) {
	int s = a.x - b.x, t = a.y - b.y;
	return sqrt(s * s + t * t);
}

int main(void) {
	int num, i;
	double s, w, ans = INF;
	point n;
	cin >> n.x >> n.y >> num;
	vector<point> d(num);
	for (i = 0; i < num; i++) {
		cin >> d[i].x >> d[i].y;
	}
	for (i = 0; i < num; i++) {
		s = area(d[i], d[(i + 1) % num], n);
		w = leng(d[i], d[(i + 1) % num]);
		ans = min(ans, s / w);
	}
	printf("%.10lf\n", ans);
	return 0;
}