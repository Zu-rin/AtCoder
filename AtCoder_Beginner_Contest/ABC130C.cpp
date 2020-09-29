#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
	int w, h, x, y;
	cin >> w >> h >> x >> y;
	long double ans = (long double)w * (long double)h / 2;
	double sx = (double)w / 2, sy = (double)h / 2;
	cout << fixed;
	cout << setprecision(10) << ans;
	if (sx == x && sy == y)
		cout << " 1\n";
	else
		cout << " 0\n";
	return 0;
}