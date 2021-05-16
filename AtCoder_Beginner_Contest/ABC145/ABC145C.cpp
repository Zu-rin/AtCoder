#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j, k = 2;
	double l, ans = 0;
	cin >> num;
	vector<double> x(num), y(num);
	for (i = 0; i < num; i++) {
		cin >> x[i] >> y[i];
	}
	for (i = 2; i < num; i++)
		k *= i;
	for (i = 0; i < num - 1; i++) {
		for (j = i + 1; j < num; j++) {
			l = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			ans += sqrt(l) * k;
		}
	}
	for (i = 2, k = 1; i <= num; i++)
		k *= i;
	ans /= k;
	printf("%.10lf\n", ans);
	return 0;
}