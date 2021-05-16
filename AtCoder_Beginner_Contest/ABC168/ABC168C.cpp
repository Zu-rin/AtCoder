#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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
	int num, i, h, m;
	double a, b, mr, hr, k, ans;
	cin >> a >> b >> h >> m;
	mr = 6.0 * m;
	hr = 30.0 * h;
	hr += 0.5 * m;
	k = max(hr, mr) - min(hr, mr);
	if (k > 180.0)
		k = 360.0 - k;
	ans = a * a + b * b;
	ans -= 2.0 * a * b * cos(PI * k / 180.0);
	ans = sqrt(ans);
	printf("%.10lf\n", ans);
	return 0;
}