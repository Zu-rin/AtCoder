#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cmath>
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
	double x, y;
	friend Point_Coordinates operator-(Point_Coordinates& l, Point_Coordinates& r) {
		return {l.x - r.x, l.y - r.y};
	}
	friend Point_Coordinates operator+(Point_Coordinates& l, Point_Coordinates& r) {
		return { l.x + r.x, l.y + r.y };
	}
} point;

point Rotate(point a, double r) {
	// 点 a を原点中心に r 度回転させた変換先座標を返す
	point ans;
	r = PI * r / 180.0;
	ans.x = cos(r) * a.x - sin(r) * a.y;
	ans.y = sin(r) * a.x + cos(r) * a.y;
	return ans;
}

int main(void) {
	int num, i;
	point a, b;
	cin >> num;
	cin >> a.x >> a.y >> b.x >> b.y;
	double theta = 90.0 - 180.0 / num;
	double rad = PI * theta / 180;
	point v = Rotate(b - a, 360 - theta);
	v.x *= cos(rad);
	v.y *= cos(rad);
	v = v + a;
	printf("%.10lf %.10lf\n", v.x, v.y);
	return 0;
}