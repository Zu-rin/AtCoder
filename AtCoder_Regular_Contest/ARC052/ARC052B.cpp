#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

double Cone(double r, double h) {
	return r * r * M_PI * h / 3.0;
}

int main(void) {
	int num, i, j, q, x, r, h, l;
	double a;
	cin >> num >> q;
	vector<double> d(20000, 0.0);
	rep(i, num) {
		cin >> x >> r >> h;
		vector<double> s(h + 1, 0.0);
		for (j = 1; j <= h; j++) {
			a = (double)(r * j) / (double)h;
			s[h - j] = Cone(a, (double)j);
		}
		rep(j, h) {
			d[x + j] += s[j] - s[j + 1];
		}
	}
	for (i = d.size() - 1; i > 0; i--) {
		d[i - 1] += d[i];
	}
	rep(i, q) {
		cin >> l >> r;
		printf("%.10lf\n", d[l] - d[r]);
	}
	return 0;
}