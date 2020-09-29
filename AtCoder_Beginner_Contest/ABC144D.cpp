#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

double TriM(double T, double a) {
	return T / a * 2.0;
}

int main(void) {
	int num, i;
	double a, b, T, ans;
	const double pi = 3.141592653589793;
	cin >> a >> b >> T;
	if (T > a * a * b / 2.0) {
		T = TriM(a * a * b - T, a);
		ans = atan2(T / a, a);
	}
	else {
		T = TriM(T, a);
		ans = atan2(b, T / b);
	}
	ans = ans * 180 / pi;
	printf("%.10lf\n", ans);
	return 0;
}