#include <iostream>

using namespace std;

int main(void) {
	long long n, m, d;
	double ans;
	cin >> n >> m >> d;
	ans = ((double)m - 1.0) / (double)(n * n);
	if (d == 0)
		ans *= (double)n;
	else
		ans *= (double)((n - d) << 1);
	printf("%.9lf\n", ans);
	return 0;
}