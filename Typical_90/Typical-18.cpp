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

int main(void) {
	int num, i;
	double t, l, x, y, e;
	cin >> t >> l >> x >> y >> num;
	l /= 2.0;
	rep(i, num) {
		cin >> e;
		double rad = 2.0 * PI * e / t;
		double py = -sin(rad) * l, pz = -cos(rad) * l + l;
		double r = sqrt(x * x + pow(y - py, 2.0)), ans = 90.0;
		if (r != 0.0)
			ans = abs(atan(pz / r)) * 180 / PI;
		printf("%.10lf\n", ans);
	}
	return 0;
}