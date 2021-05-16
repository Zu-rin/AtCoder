#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int l, x, y, s, d;
	double ans;
	cin >> l >> x >> y >> s >> d;
	d -= s;
	if (d < 0)
		d += l;
	ans = (double)d / (double)(x + y);
	if (y > x) {
		ans = min(ans, (double)(l - d) / (double)(y - x));
	}
	printf("%.9lf\n", ans);
	return 0;
}