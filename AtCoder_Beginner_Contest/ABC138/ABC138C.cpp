#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i;
	double ans = 0.0;
	cin >> num;
	vector<double> d(num);
	for (i = 0; i < num; i++)
		cin >> d[i];
	sort(d.begin(), d.end());
	ans = d[0];
	for (i = 1; i < num; i++) {
		ans += d[i];
		ans /= 2.0;
	}
	printf("%.9lf\n", ans);
	return 0;
}