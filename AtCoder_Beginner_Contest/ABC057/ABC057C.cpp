#include <iostream>
#include <cmath>

using namespace std;

int Func(long long a) {
	int i = 0;
	while (a > 0) {
		a /= 10;
		i++;
	}
	return i;
}

int main(void) {
	long long n;
	cin >> n;
	int ans = Func(n), i = 2;
	for (; i <= sqrt(n); i++) {
		if (n % i == 0)
			ans = Func(n / i);
	}
	cout << ans << "\n";
	return 0;
}