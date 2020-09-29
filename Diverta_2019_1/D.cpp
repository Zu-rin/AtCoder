#include <iostream>
#include <cmath>
#define MAX 1000000000000L
using namespace std;

int main(void) {
	long long n, i = 1, k, buf = MAX, sum;
	cin >> n;
	if (n == 2) {
		printf("0\n");
		return 0;
	}
	k = (long long)sqrt(n) + 1;
	n--;
	sum = n;
	while (buf > k) {
		n--;
		i++;
		buf = n / i;
		if (n % i == 0)
			sum += buf;
	}
	cout << sum << "\n";
	return 0;
}