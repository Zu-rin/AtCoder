#include <iostream>

using namespace std;

int main(void) {
	int n, k, i = 1;
	long long sum = 0, ss = 0;
	cin >> n >> k;
	if (k & 1) {
		for (; i <= n; i++) {
			if (i % k == 0)
				sum++;
		}
	}
	else {
		for (; i <= n; i++) {
			if (i % k == 0)
				sum++;
			else if (i % k == (k >> 1))
				ss++;
		}
		ss = ss * ss * ss;
	}
	cout << sum * sum * sum + ss << "\n";
	return 0;
}