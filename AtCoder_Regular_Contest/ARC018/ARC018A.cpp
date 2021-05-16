#include <iostream>

using namespace std;

int main(void) {
	double h, bmi;
	cin >> h >> bmi;
	h /= 100.0;
	printf("%lf\n", bmi * h * h);
	return 0;
}