#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int ax, ay, bx, by, cx, cy;
	double S, r, a, b, c, m = 0.0, ans = 0.0;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	bx -= cx;
	by -= cy;
	ax -= cx;
	ay -= cy;
	cx = cy = 0;
	S = abs(ax * by - bx * ay);
	a = sqrt(abs(ax - bx) * abs(ax - bx) + abs(ay - by) * abs(ay - by));
	b = sqrt(abs(ax - cx) * abs(ax - cx) + abs(ay - cy) * abs(ay - cy));
	c = sqrt(abs(cx - bx) * abs(cx - bx) + abs(cy - by) * abs(cy - by));
	r = S / (a + b + c);
	a = max(a, max(b, c));
	ans = a * r / (2.0 * r + a);
	printf("%.10lf\n", ans);
	return 0;
}