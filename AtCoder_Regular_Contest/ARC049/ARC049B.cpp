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
typedef pair<int, int> pp;

int Judge(double p, vector<double> & x, vector<double> & y, vector<double> & c) {
	int i;
	double lx, hx, ly, hy;
	lx = ly = -1e5;
	hx = hy = 1e5;
	rep(i, c.size()) {
		double d = p / c[i];
		chmax(lx, x[i] - d);
		chmax(ly, y[i] - d);
		chmin(hy, y[i] + d);
		chmin(hx, x[i] + d);
	}
	if (lx > hx || ly > hy)
		return 0;
	return 1;
}

int main(void) {
	int num, i;
	double l = 0, r = 1e9;
	cin >> num;
	vector<double> x(num), y(num), c(num);
	rep(i, num)
		cin >> x[i] >> y[i] >> c[i];
	while (r - l > 1e-6) {
		double p = (l + r) / 2.0;
		if (Judge(p, x, y, c))
			r = p;
		else
			l = p;
	}
	printf("%.10lf\n", l);
	return 0;
}