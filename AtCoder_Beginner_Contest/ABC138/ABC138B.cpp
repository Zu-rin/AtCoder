#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int num, i;
	double a, sum = 0.0;
	cin >> num;
	for (i = 0; i < num; i++) {
		cin >> a;
		sum += 1.0 / a;
	}
	printf("%.9lf\n", 1.0 / sum);
	return 0;
}