#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	string s;
	int num, i = 0;
	double ans = 0.0;
	cin >> num >> s;
	for (; i < num; i++) {
		if (s[i] != 'F')
			ans += 4 - (s[i] - 'A');
	}
	printf("%.10lf\n", ans / num);
	return 0;
}