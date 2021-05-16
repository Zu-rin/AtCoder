#include <iostream>
#include <cmath>

using namespace std;

double h = 0.5;

double Prob(int n, int k) {
	int num = 0;
	while (n < k) {
		n <<= 1;
		num++;
	}
	return pow(h, num);
}

int main(void) {
	int n, k;
	double ans = 0.0, d;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		ans += Prob(i, k);
	printf("%.12lf\n", ans / n);
	return 0;
}