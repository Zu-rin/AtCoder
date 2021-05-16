#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(void) {
	int num, n, i, a = 2;
	bool p = true;
	cin >> num;
	if ((num & 1) == 0) {
		printf("NO\n");
		return 0;
	}
	n = (int)sqrt(num) + 1;
	vector<int> d(n, false);
	while (a < n) {
		for (i = a; i < n; i += a)
			d[i] = true;
		while (a < n && d[a])
			a++;
		if (num % a == 0) {
			p = false;
			break;
		}
	}
	if (p)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}