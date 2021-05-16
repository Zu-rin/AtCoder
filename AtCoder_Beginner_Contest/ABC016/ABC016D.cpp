#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

typedef struct Point_Coordinates {
	double x, y;
} point;

int Judge(point &a, point &b, point &c, point &d) {
	double s, t;
	s = (a.x - b.x) * (c.y - a.y) - (a.y - b.y) * (c.x - a.x);
	t = (a.x - b.x) * (d.y - a.y) - (a.y - b.y) * (d.x - a.x);
	if (s * t > 0)
		return false;

	s = (c.x - d.x) * (a.y - c.y) - (c.y - d.y) * (a.x - c.x);
	t = (c.x - d.x) * (b.y - c.y) - (c.y - d.y) * (b.x - c.x);
	if (s * t > 0)
		return false;
	return true;
}

int main(void) {
	int num, i, ans = 0;
	double k;
	point A, B;
	cin >> A.x >> A.y >> B.x >> B.y >> num;
	vector<point> d(num);
	for (i = 0; i < num; i++) {
		cin >> d[i].x >> d[i].y;
	}
	for (i = 0; i < num - 1; i++) {
		if (Judge(A, B, d[i], d[i + 1]))
			ans++;
	}
	if (Judge(A, B, d[0], d[num - 1]))
		ans++;
	cout << ans / 2 + 1 << "\n";
	return 0;
}